class Solution:
    def min_horses(self, sound: str) -> int:
        # Initialize counters for each character in 'neigh'
        counts = {'n': 0, 'e': 0, 'i': 0, 'g': 0, 'h': 0}
        num_horses = 0

        for char in sound:
            # Increment the counter for the current character
            if char in counts:
                counts[char] += 1

                # If the current character is 'n', check if we can decrement all counters
                if char == 'n' and all(counts.values()):
                    for key in counts:
                        counts[key] -= 1
                # Update the maximum number of horses needed
                num_horses = max(num_horses, counts['n'])

        return num_horses
