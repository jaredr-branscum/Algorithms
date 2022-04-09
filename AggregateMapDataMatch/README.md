# Aggregate Map Data Matches
Input: Given a Map Data Structure Map<string, HobbyProfile> where the key is the string representation of a person's unique identifier (i.e. SSN, etc.) and the value pair represents that person's profile of hobbies.

Output: Return a data structure that is composed of each unique hobby with the total sum of each person's budget towards that hobby along with a field containing the sum of everyone's hobbies

Time Complexity: O(N * M) where N = number of key value pairs in the map and M = the size of HobbyProfile's array of Hobbies
Space Complexity: O(N * M) where N = number of key value pairs in the map and M = the size of HobbyProfile's array of Hobbies

HobbyProfile: A data structure that has the two following properties:
* HobbyBudget: An object array with the following properties: {hobby: string, budget: number} 0 <= budget < INFINITY
* Hobbies: array of strings containing the person's hobbies
* A member of Hobbies is not guaranteed to be a member of the Hobby Budget
* Any hobby in HobbyBudget must exist in the array of Hobbies