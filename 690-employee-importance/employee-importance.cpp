class Solution {
public:
    // Maps employee ID -> Employee object pointer
    // This allows O(1) lookup of an employee using its ID.
    unordered_map<int, Employee*> mp;

    // DFS function to calculate the total importance
    // of the given employee and all of their subordinates.
    int dfs(int id) {

        // Get the Employee object corresponding to the given ID
        Employee* emp = mp[id];

        // Start with the employee's own importance
        int ans = emp->importance;

        // Visit each subordinate recursively
        for (int child : emp->subordinates) {

            // Add the subordinate's total importance
            ans += dfs(child);
        }

        // Return the total importance of this subtree
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {

        // Build a lookup table:
        // Employee ID -> Employee pointer
        // This avoids searching the entire vector every time.
        for (Employee* emp : employees) {
            mp[emp->id] = emp;
        }

        // Start DFS from the given employee
        return dfs(id);
    }
};

/*
-------------------------------- INTUITION --------------------------------

The subordinates list stores only employee IDs, not the actual Employee objects.

Example:

Employee 1
importance = 5
subordinates = {2, 3}

Employee 2
importance = 3

Employee 3
importance = 4

To process subordinate 2, we must first find the Employee object
whose id == 2.

Without a map:
    Every lookup requires scanning the entire employees vector.
    Time Complexity becomes O(n^2).

With a map:
    ID -> Employee pointer
    Finding an employee takes O(1) on average.

Algorithm:
1. Build a hash map from employee ID to Employee pointer.
2. Perform DFS starting from the given employee.
3. At each employee:
      - Add their own importance.
      - Recursively visit every subordinate.
4. Return the accumulated importance.

Time Complexity:
    Building map : O(n)
    DFS          : O(n)
    Overall      : O(n)

Space Complexity:
    Hash Map : O(n)
    DFS Stack: O(h) (up to O(n) in the worst case)
*/