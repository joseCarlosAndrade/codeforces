#include <vector>
#include <climits>

using namespace std;

// Function to check if the books can be allocated to students such that no student gets more than 'maxPages'
bool isPossible(const vector<int>& pages, int n, int m, int maxPages) {
    int studentCount = 1;  // Start by assigning to the first student
    int pagesSum = 0;

    for (int i = 0; i < n; ++i) {
        if (pages[i] > maxPages) {
            return false;  // If a single book has more pages than maxPages, it's impossible to assign
        }

        if (pagesSum + pages[i] > maxPages) {
            // Assign the current book to a new student
            studentCount++;
            pagesSum = pages[i];

            if (studentCount > m) {
                return false;  // If students exceed the limit, return false
            }
        } else {
            // Continue adding pages to the current student
            pagesSum += pages[i];
        }
    }

    return true;
}

// Function to find the minimum of the maximum pages allocation
int findMinPages(const vector<int>& pages, int n, int m) {
    if (n < m) {
        return -1;  // If there are more students than books, it's impossible
    }

    int low = *max_element(pages.begin(), pages.end());  // The minimum possible value of maxPages
    int high = accumulate(pages.begin(), pages.end(), 0);  // The maximum possible value of maxPages
    int result = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;  // Update result with the current mid value
            high = mid - 1;  // Try for a lower maximum
        } else {
            low = mid + 1;  // Increase the possible maximum value
        }
    }

    return result;
}


int main() {

    int n, m;
    
    // Input number of books and students
    cout << "Enter the number of books: ";
    cin >> n;
    cout << "Enter the number of students: ";
    cin >> m;
    
    vector<int> pages(n);
    
    // Input pages in each book
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    
    int result = findMinPages(pages, n, m);
    
    if (result == -1) {
        cout << "Not enough books for students" << endl;
    } else {
        cout << "The minimum possible maximum number of pages is: " << result << endl;
    }

    return 0;
}