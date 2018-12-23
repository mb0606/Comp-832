
#include <iostream>
#include <string>

using namespace std;

struct PersonRec {
    string name;
    int bribe;
};

void swap(PersonRec *arr[], int l, int r );
void bubbleSort(PersonRec *arr[], int length);
void quickSort(PersonRec *arr[], int left, int right);

int main(int argc, const char * argv[]) {
    char choice;
    int sortChoice;
    int recordCount = 0;
    PersonRec** studentArray = new PersonRec*[10];
    
    do{
        cout << "Do you want to enter student (Y / N) ? ";
        cin >> choice;
        if(choice == 'Y' || choice == 'y') {
            string name;
            int bribe;
            cout << "\nEnter the person's name: ";
            cin >> name;
            cout << "\nEnter the person's contribution: ";
            cin >> bribe;
            studentArray[recordCount] = new PersonRec;
            studentArray[recordCount]->name = name;
            studentArray[recordCount]->bribe = bribe;
            recordCount++;
            cout << endl;
        }
        
    } while((choice == 'Y' || choice == 'y') && recordCount <= 10);
    
    cout << "\nMenu\n";
    cout << "==============================\n\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Please enter choice: \n";
    cin >> sortChoice;
    if(recordCount == 0){
        cout << "List is empty\n";
    } else {
        if(sortChoice == 1 && recordCount > 1){
            bubbleSort(studentArray, recordCount);
        }
        if(sortChoice == 2 && recordCount > 1){
            quickSort(studentArray, 0, recordCount - 1);
        }
        cout << "# Name Contribution\n===================\n";
        for(int i = 0; i < recordCount; i++){
            cout << i + 1 << " "
            << studentArray[i]->name << " $"
            << studentArray[i]->bribe
            <<  endl;
        }
    }
    
    for(int i = 0; i < recordCount; i++){
        delete studentArray[i];
    }
    delete[] studentArray;
    return 0;
}

void swap(PersonRec *arr[], int l, int r ){
    PersonRec *temp = new PersonRec;
    temp->name = arr[l]->name;
    temp->bribe = arr[l]->bribe;
    arr[l]->name = arr[r]->name;
    arr[l]->bribe = arr[r]->bribe;
    arr[r]->name = temp->name;
    arr[r]->bribe = temp->bribe;
    delete temp;
}

void bubbleSort(PersonRec *arr[], int length){
    
    for( int i = 0; i < length-1; i++){
        for( int j = i + 1; j < length; j++){
            if(arr[i]->bribe < arr[j]->bribe){
                swap(arr, i, j);
            }
        }
    }
    
    
}
void quickSort(PersonRec *arr[], int left, int right){
    if(left >= right){
        return;
    }
    int l = left;
    int r = right;
    int pivot = (left + right) / 2;
    
    while(l <= r){
        while(arr[l]->bribe < arr[pivot]->bribe){
            l++;
        }
        while(arr[r]->bribe > arr[pivot]->bribe){
            r--;
        }
        if(l <= r){
            swap(arr, l, r);
            l++;
            r--;
            
        }
    }
    //left value must be less the new right value
    if(left < r) {
        //pass in the array, left most value of array, r new right value
        quickSort(arr, left, r);
    }
    // right value must be greater than new left value
    if(l < right) {
        // pass in array, new left value, right most value
        quickSort(arr, l , right);
    }
    
    
}
