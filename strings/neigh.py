'''
PROBLEM STATEMENT:

How many horses are there a string with multiple 'neighs' in it;
Given a string (of horse sound 'neigh'),
determine the minimum number of horses possible.
'Nneigheigh' should return 2, 'neighneigh' returns 1.
'''


def min_horses(sound: str) -> int:
    # Initialize counters for each character in 'neigh'
    counts = {'n': 0, 'e': 0, 'i': 0, 'g': 0, 'h': 0}
    max_horses = 0

    for char in sound:
        # Increment the counter for the current character
        if char in counts:
            counts[char] += 1

            # If the current character is 'n', check if we can decrement all counters
            if char == 'n' and all(counts.values()):
                for key in counts:
                    counts[key] -= 1
            # Update the maximum number of horses needed
            max_horses = max(max_horses, counts['n'])

    return max_horses


if __name__ == '__main__':
    print(f"'neigh': {min_horses('neigh')}")
    print(f"'neighneigh': {min_horses('neighneigh')}")
    print(f"'nneigheigh': {min_horses('nneigheigh')}")
    print(f"'nneingheighigh': {min_horses('nneingheighigh')}")
