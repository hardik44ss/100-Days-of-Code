public class MergeSort {
    
    public static void main(String[] args) {
    
        int arr[] = { 5, 3, 7, 2, 4, 6, 2, 7, 5, 8 };
        System.out.println("Before Sorting : ");
        for(int i = 0 ;i<10;i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        mergeSort(arr, 0, 9);

        System.out.println("After Sorting : ");
        for(int i = 0 ;i<10;i++){
            System.out.print(arr[i] + " ");
        }
    }
    public static void mergeSort(int[] arr, int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = s + (e-s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr,mid+1,e);

        merge(arr, s ,e);
    }
    public static void merge(int [] arr, int s ,int e ){
        int mid = s + (e-s)/2;
        int len1 = mid - s +1;
        int len2 = e-mid;

        int[] arr1 = new int[len1];
        int[] arr2 = new int[len2];

        int curr1 = s ; 
        for(int i =0; i < len1 ; i++){
            arr1[i] = arr[curr1++];
        }

        // int curr2 = mid + 1 ;
        for( int i =0 ; i<len2 ;i++){
            arr2[i] = arr[curr1++];
        }

        int i=0,j=0;
        int mainIndex = s;
        while(i<len1 && j<len2){
            if(arr1[i] < arr2[j]){
                arr[mainIndex++] = arr1[i++];
            }
            else{
                arr[mainIndex++] = arr2[j++];
            }
        }

        while(i<len1){
            arr[mainIndex++] = arr1[i++];
        }

        while(j<len2){
            arr[mainIndex++] = arr2[j++];
        }

    }

}
