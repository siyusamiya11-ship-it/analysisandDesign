import matplotlib.pyplot as plt

def binary_search_graph(arr, target):
    low = 0
    high = len(arr) - 1

    steps = []
    mids = []

    step = 1

    while low <= high:
        mid = (low + high) // 2

        steps.append(step)
        mids.append(mid)

        if arr[mid] == target:
            print(f"Element found at index {mid}")
            break
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

        step += 1

    # Plot graph
    plt.plot(steps, mids, marker='o')
    plt.xlabel("Steps")
    plt.ylabel("Mid Index")
    plt.title("Binary Search Process Visualization")
    plt.grid()

    plt.show()


# Example
arr = [2, 3, 4, 5, 6, 7, 8]
target = 5

binary_search_graph(arr, target)
