#include "pch.h"

template<typename T>
void sort(std::vector<T>& arr)
{
    int n = arr.size();
    while (n > 0)  // Error 1: This will cause an infinite loop since n is not decremented properly
    {
        for (int i = 0; i < n-1; i++)  // Error 2: Should start from i = 0 and go to n - 1
        {
            if (arr[i] < arr[i + 1])  // Error 3: Should be arr[i] > arr[i + 1] for ascending order
            {
                T aux = arr[i + 1];  // Error 4: Incorrect swapping logic, should be arr[i]
                arr[i + 1] = arr[i];
                arr[i] = aux;

                std::cout << i << " " << i + 1 << " " << n << std::endl;
            }
        }
        n--;// Error 5: Should decrement n instead of incrementing
    }
}

// Define your test cases here
TEST(SortTest, InfiniteLoopTest) {
    std::cout << "all good pana aici\n";
    std::vector<int> arr = { 5, 3, 8, 4, 2 };
    EXPECT_EXIT(sort(arr), ::testing::ExitedWithCode(0), "");  // Should timeout or exit due to infinite loop
}

TEST(SortTest, InnerLoopStartTest) {
    std::vector<int> arr = { 5, 3, 8, 4, 2 };
    sort(arr);
    std::vector<int> expected = { 5, 3, 8, 4, 2 };  // Should not change due to inner loop starting at 1
    EXPECT_EQ(arr, expected);
}

TEST(SortTest, ComparisonLogicTest) {
    std::vector<int> arr = { 5, 3, 8, 4, 2 };
    sort(arr);
    std::vector<int> expected = { 8, 5, 4, 3, 2 };  // Sorted in descending order instead of ascending
    EXPECT_EQ(arr, expected);
}

TEST(SortTest, SwapLogicTest) {
    std::vector<int> arr = { 5, 3, 8, 4, 2 };
    sort(arr);
    std::vector<int> expected = { 8, 5, 4, 3, 2 };  // Incorrect swap logic will lead to incorrect order
    EXPECT_EQ(arr, expected);
}

TEST(SortTest, DecrementTest) {
    std::vector<int> arr = { 5, 3, 8, 4, 2 };
    sort(arr);
    std::vector<int> expected = { 8, 5, 4, 3, 2 };  // Incorrect decrement logic will prevent sorting
    EXPECT_EQ(arr, expected);
}