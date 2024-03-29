#include <iostream> 

 using namespace std; 

void display(int arr[], int size) 
 {
   for (int i = 0; i < size; i++)

		cout << arr[i] << " ";

    cout << "\n";
 }

int getMax(int arr[], int n) 
{ 
	int max = arr[0]; 
	
	for (int i = 1; i < n; i++) 
		
		if (arr[i] > max) 
		
			max = arr[i]; 
	
	return max; 
} 

void counting_sort(int arr[], int n, int exp) 
{ 
	int output[n];  
	int i, count[10] = { 0 };         // [21,48,12,4,60,62]  

	for (i = 0; i < n; i++) 

		count[(arr[i] / exp) % 10]++; 

	for (i = 1; i < 10; i++) 

		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) 
	  { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];           
		count[(arr[i] / exp) % 10]--; 
	  } 
	
	for (i = 0; i < n; i++) 
		
		arr[i] = output[i]; 
} 


void radix_sort(int arr[], int n) 
{ 
	int m = getMax(arr, n); 

	for (int exp = 1; m / exp > 0; exp *= 10) 

		counting_sort(arr, n, exp); 
} 

int main()
 {
  
  int n ;
 	
  cout << "\nEnter the Number of Elements: ";
  cin >> n;
		    
  int arr[n] ;

  cout << "\nEnter the Elements: ";
					
  for (int i = 0; i < n; i++) 
	 
      cin >> arr[i] ;

  cout << "\nArray before Sorting: ";
                   
  display(arr, n);

  radix_sort(arr, n) ;

  cout << "\nArray After Radix Sorting: ";
                    
  display(arr, n);
     
 	return 0;
 }
