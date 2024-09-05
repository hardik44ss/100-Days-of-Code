// Java program to count inversions in an array
public class inversionCount {
    public static void main(String[] args) {
        int arr[] = {4, 3, 2, 1};
        System.out.println("Total number of inversion Count : " + getInvCount(arr));
    }

    // Function to count inversions in the array
    static int getInvCount(int arr[]) {
        int n = arr.length; 
        int inv_count = 0;  

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // If the current element is greater than the next,
                // increment the count
                if (arr[i] > arr[j])
                    inv_count++;
            }
        }
        return inv_count; 
    }
    
}
