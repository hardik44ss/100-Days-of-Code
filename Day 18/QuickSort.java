public class QuickSort {

    public static void main(String[] args) {
        int arr[] = {4, 3, 5, 23, 5, 29, 6, 36, 25, 12};
        System.out.println("Before Sorting: ");
        for (int n : arr) {
            System.out.print(n + " ");
        }
        System.out.println();

        quickSort(arr, 0, arr.length - 1); // Use arr.length - 1 for the end index

        System.out.println("After Sorting: ");
        for (int n : arr) {
            System.out.print(n + " ");
        }
    }

    public static void quickSort(int[] arr, int s, int e) {
        if (s >= e) {
            return;
        }

        int pivot = partition(arr, s, e);

        quickSort(arr, s, pivot - 1);
        quickSort(arr, pivot + 1, e);
    }

    public static int partition(int arr[], int s, int e) {
        int pivotValue = arr[s]; // Choose the first element as pivot
        int i = s + 1; // Pointer starting after pivot
        int j = e;     // Pointer starting from the end

        while (i <= j) {
            // Find elements that are larger than pivot on the left side
            while (i <= j && arr[i] <= pivotValue) {
                i++;
            }
            // Find elements that are smaller than pivot on the right side
            while (i <= j && arr[j] > pivotValue) {
                j--;
            }

            // If we find an element out of place, swap them
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Place pivot in the correct position (swap with j)
        arr[s] = arr[j];
        arr[j] = pivotValue;

        // Return the pivot index
        return j;
    }
}
