#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

/* оголошуємо прототипи наших функцій */
void initializeField(int **field, int n);
void printField(int **field, int n);
bool isWin(int **field, int n);
bool moveTile(int tile ,int **field, int n);


int main()
{
    int n; // змінна для визначеня розміру поля
    cout << "Input size :";
    cin >> n;
    while(n < 3 || n > 9){
        system("CLS"); // очищаємо консоль
        cout << "Input size from 3 to 9:";
        cin >> n;
    };
    system("CLS");
    
    /* 
    створюємо двовимірний масив, в якому
    будемо зберігати положеня плиток
    */
    int **arr = new int* [n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    /* починаємо гру */    
    int tile; // змінна в якій зберігається номер плитки, яку будемо пересувати
    initializeField(arr, n); // ініціалізуємо поле для гри
    printField(arr, n); // малюємо ігрове поле
    
    /* цикл який буде тривати до перемоги */
    while (!isWin(arr, n)){
        cin >> tile; // зчитуємо номер плитки для переміщення
        
        if (!moveTile(tile,arr,n)){ // якщо таке переміщеня неможливе
            printField(arr, n); // перемальовуємо поле
            cout << "forbidden move\n"; 
        }
        else printField(arr, n); // малюємо поле після переміщення плитки
    }
    
    system("CLS"); // очищаємо консоль
    cout << "you win";
    
    // видаляємо створені масиви
    for(int i = 0; i < n; i++){
        delete arr[i];
    }
    delete[] arr;
    
    return 0;
}

/* функція initializeField повинна заповнювати поле плитами від n*n-1 до 0.
Якщо розмір поля парний, потрібно поміняти два перших елемента місцями.
для поля n*n n=3:
8 7 6
5 4 3
2 1 0

для поля n*n n=4:
14 15 13 12 
11 10  9  8
 7  6  5  4
 3  2  1  0
*/
void initializeField(int **field, int n){
    
}


/* функція printField вже реалізована, вона відображає ігрове поле */
void printField(int **field, int n){
    system("CLS"); //очищаємо консоль
    
   /* проходимось по всіх елемнтах поля */
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (field[i][j] != 0){ // якщо елемент поля не 0 (0 відображає пусте міце)
                cout << setfill('0') << setw(2) << field[i][j] << "  "; //виводимо значення елемента поля
            }
            else { // інакше (елемент поля =0)
                cout << "__  "; 
            }
        }
        cout << endl;
    }
}


/* потрібно реалізувати функцію isWin, яка буде перевіряти чи поле знаходится
у виграшному положенні та повертати true якщо положення є виграшним. Виграшне
положення для поля 3х3 буде виглядати так:
1 2 3
4 5 6
7 8 0
*/
bool isWin(int **field, int n){
    
    return true;
}

/* потрібно реалізувати функцію moveTile, яка буде міняти місцями порожнє місце 
на полі field з введеним номером плитки  tile. Якщо порожня плитка знаходится зверху,
або ліворуч, або праворуч, або знизу від плитки tile яку хочемо переміщати, потрібно
поміняти їх місцями та повернути true */

bool moveTile(int tile ,int **field, int n){    
    
    return false;
}

