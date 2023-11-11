import subprocess
import os
import re
from typing import List, Any


# Define the paths to your build directory and test directory
build_directory = "../../build"  # "/path/to/your/build/directory"
test_directory = "./"  # "/path/to/your/test/directory"

# Define the regex patterns to find the test names and times
cpp_test_pattern = re.compile(r"(test\d+_.+?)\s+time: ([\d.e-]+) s")
python_test_pattern = re.compile(r"(test\d+_.+?)\s+time: ([\d.e-]+) s")


def add_subdirectory() -> None:
    CMakeLists_subdir_pattern = re.compile(r"add_subdirectory\(([^)]+)\)")
    cwd_name = os.getcwd().split('/')[-1]
    with open("../CMakeLists.txt", 'r+') as CMakeLists_file:
        file_content = CMakeLists_file.read()
        subdirs_list = CMakeLists_subdir_pattern.findall(file_content)
        if cwd_name not in subdirs_list:
            CMakeLists_file.seek(0, 2)
            CMakeLists_file.write(f"add_subdirectory({cwd_name})\n")


# Function to run tests and capture the output
def run_tests(command: List[str], pattern: re.Pattern, working_directory: str, language: str) -> List[Any]:
    original_directory = os.getcwd()
    os.chdir(working_directory)

    if language == "C++":
        # Run 'make'
        make_process = subprocess.run(['make'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print("Output of 'make':\n", make_process.stdout.decode())
        print("Errors of 'make':\n", make_process.stderr.decode() if make_process.stderr.decode() != '' else None)

        # Check if 'make' was successful before running tests
        if make_process.returncode == 0:
            # Run 'ctest'
            result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        else:
            print("'make' failed with return code", make_process.returncode)
    elif language == "Python":
        result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    else:
        raise ValueError("Unsupported Language")

    os.chdir(original_directory)
    matches = pattern.findall(result.stdout)

    return matches


# Function to create the markdown table from the test results
def create_markdown_table(test_results: List[Any], language: str) -> str:
    table = f"## {language} Test Times\n\n"
    table += "| Test Name | Time Spent |\n"
    table += "| --- | --- |\n"
    for name, time in test_results:
        table += f"| {name} | {time} s |\n"

    return table


# Append current folder to the end of CMakeLists.txt file with add_subdirectory()
add_subdirectory()

test_name = [filename.split('.')[0] for filename in os.listdir() if filename.startswith('test_') and filename.endswith('.py')][0]
# Run C++ and Python tests
cpp_test_command = ["ctest", "-R", f"{test_name}", "-V"]
cpp_test_results = run_tests(cpp_test_command, cpp_test_pattern, build_directory, "C++")

python_test_command = ["python", f"{test_name}.py"]
python_test_results = run_tests(python_test_command, python_test_pattern, test_directory, "Python")

# Create markdown tables
cpp_markdown_table = create_markdown_table(cpp_test_results, "C++")
python_markdown_table = create_markdown_table(python_test_results, "Python")

# Combine the markdown tables
combined_markdown = f"# Test Results\n\n{cpp_markdown_table}\n{python_markdown_table}"

# Write the markdown content to README.md
with open('README.md', 'w') as file:
    file.write(combined_markdown)

# Print a message
print("README.md has been created with the test results.")
