/*************************************************************
	Практическое занятие №4. Встроенные массивы.
							Простейшие алгоритмы сортировки и поиска.
							
*************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#define	  stop __asm ("nop");
using namespace std;
int main()
//Задания, помеченные * не являются обязательными. Но выполнение их крайне желательно!!!
{
/*
            Указатели (продолжение)
*/

		//Задание 1. Модификатор const. 
    /*В каждом из заданий объявите указатель требуемого вида.
    Посредством каждого указателя попробуйте:
    1) получить значение по адресу
    2) записать новое значение по адресу
    3) модифицировать указатель
Замечания:
1.операторы явного преобразования типа использовать не следует
2.если компилятор не позволяет выполнить операцию, то комментируйте эту строку с пояснением */
    //Задание 1a. Указатель является константой.
    {int x;
        int * const p = &x; // p получает значение &x
        *p = 10;
        int y=100;
        //p = &y; // ошибка, нельзя изменять p
    }


		//Задание 1б. Указываемое значение является константой.

               { int x;
                const int * p;
                p = &x;
                int y;
                p = &y; // можно изменять p
            // *p = 10; //ошибка, нельзя изменять *p
                }

// *******************************************************

/*
		//Задание 1в. И указатель, и указываемое значение
        //являются константами. */
                {int x;
                 const int * const p = &x;
                 int y;
                //p = &y; // ошибка, нельзя изменять p
               // *p = 10; // ошибка, нельзя изменять *p
                }

	stop

// *******************************************************

/*
		//Задание 1г. Указатель на переменную, объявленную с
        //ключевым словом const. */
    {const int nN = 1;
	//Объявите указатель и проинициализируйте его выражением - &nN	
    const int *p=&nN;}
	stop


//*******************************************************
	//Задание 1д. const  и void-указатель. 
	{
		//1) Что нужно сделать для того, чтобы следующее закомментированное выражение
		//стало корректным?
        const int n = 1; //нельзя константу присвоить pn = &k
        int k=10;
        void * pn;
        pn = &k;
		//2) как получить значение посредством  void* ?
        //Указатель не может быть разыменован, если он не приводится к другому типу. void*
	}
//*******************************************************
//
	//Задание 2. Явное преобразование указателя. 
	//Иногда возникает необходимость одни и те же данные интерпретировать по-разному,

	//например, целое можно представить как совокупность четырех
	//байтов и работать с каждым байтом по отдельности. Для этого
	//нужно иметь возможность "указывать" как на целое, так и на байт. 

	//Следовательно, возникает необходимость явного преобразования указателя. 

	//Подсказка: для правильной интерпретации этого задания воспользуйтесь
	//возможностями отладчика представлять данные в интересующем
	//Вас виде (в данном случае - в шестнадцатеричном) - для
	//этого используйте правую клавишу мыши,находясь в окне

	//переменных и изменяйте пункт - Hexadecimal display !!!!!!!!!!!!!!!!!


	unsigned int nObject5=0x55667788;
    unsigned int * pnObject5=&nObject5;

	//Раскомментировав следующую строчку кода, обратите внимание на сообщение компилятора 
	//- он не считает преобразование "легальным" (безопасным)

	unsigned char* pucObject5;

    //pucObject5= static_cast<unsigned char*>(pnObject5);	//(1)

	pucObject5=reinterpret_cast<unsigned char*>(pnObject5);	//а такое
				//преобразование - целиком на совести программиста.
				//Его можно применять, только четко представляя себе
				//результат преобразования (2)

	//Откомментируйте (!) следующие строчки следующим образом:
	// сс=..., 	pucObject5 - изменился? 	*pucObject5=...


    char cc = *(pucObject5++);	//    cc=0x88 ' €'	char
    //pucObject5	0x002cf809 "wfUММММММММ\x1"	unsigned char *

	cc = (*pucObject5)++;		//

	cc = ++*(pucObject5);		//
	cc = *(++pucObject5);		//
    stop

///////////////////////////////////////////////////////////////
//			Встроенные массивы                               
///////////////////////////////////////////////////////////////

	//Задание 3. 
	//Имеется одномерный встроенный массив, проинициализированный при объявлении 
	//Отсортируйте массив по возрастанию значений. 
	//Используйте "пузырьковую" сортировку  
	// Правильность решения проверьте с помощью отладчика

	{
        int ar[] = { 5, 4, 7,  8, 1, 2, 6, 0, 10, 12, 77, 11,
                         6, 8, 33, 21, 1, 2, 3, 4};
        int N=sizeof (ar)/sizeof (ar[0]);
          for(int i = 1; i < N; ++i)
          {
              for(int j = 0; j < N-i; j++)
                 {
                     if(ar[j] < ar[j+1])
                        { int temp = ar[j];
                            ar[j] = ar[j+1];
                                ar[j+1] = temp;
                            }
                    }
             }
       cout << "Отсортированный массив: ";
          for(int i = 0; i < N; ++i)
          {
            cout << ar[i] << " ";
             }
             cout << endl;
    }
// *******************************************************
	//Задание 4  
	//в)Инициализация массива строковыми литералами:
	//Объявите одномерный массив УКАЗАТЕЛЕЙ и проинициализируйте его СТРОКОВЫМИ литералами . 
	//Выведите  массив на печать.
   {
        char m[]={"Massiv"};
        const char *cm []{m,m+1,m+2,m+3,m+4,m+5};
    uint N= sizeof (m)/sizeof (*cm[0]);
    for(int i = 0; i < N; ++i)
    {
      cout << cm[i] << " ";
       }
       cout << endl;
    }
// *******************************************************
	//Задание 5. 
	//a) Объявите одномерный неинициализированный массив ( размером N)
	//Задайте значения элементов с помощью генератора случайных чисел.
        {const int N=10;
        srand(time(0));
        int arr[N];
        for (int i= 0; i<10; i++)
        {
            int v = rand() % 100;   // v1 в диапазоне 0 - 99
            arr[i] = v;
            cout << arr[i] << ' ' << endl;
          }

	//Подсказка 1: для генерации случайных чисел используйте функцию
	//стандартной библиотеки - rand() (<cstdlib>)
	// int tmp= rand(); // получим случайное значение в диапазоне от 0 до RAND_MAX
    	//значение RAND_MAX задано в файле <stdlib.h>  и равно  0x7fff
	
	//если Вам требуется задать иные границы диапазона при генерации случайного числа, 
	//то это можно сделать так:
	//v1 = rand() % 100;         // v1 в диапазоне 0 - 99
	//v2 = rand() % 100 + 1;     // v2 в диапазоне 1 - 100
	//v3 = rand() % 30 + 1985;   // v3 в диапазоне 1985-2014 
	
	//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
	//чисел являются «псевдослучайными», то есть при двух последовательных запусках
	//приложения Вы получаете две одинаковые последовательности значений.
	//Для того чтобы генерируемые "случайные" значения были разными при каждом 
	//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
	//и time() (<ctime>).
	//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
	//Функция time() задает эту точку отсчета, считывая текущее время
	//srand( time( 0 ) );
//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)


	//б) Выведите массив на печать
    //cout << arr[N] << ' ' << endl;
    //в)Отсортируйте массив по убыванию значений.
	//Используйте сортировку "выбором"
    //сортировка выбором
        {
            int max = 0; // для записи максимального значения
            int buf = 0; // для обмена значениями
            for (int i = 0; i < N; i++)
             {
             max = i;           // запомним номер текущей ячейки, как ячейки с минимальным значением
                                // в цикле найдем реальный номер ячейки с максимальным значением
             for (int j = i + 1; j < N; j++)
             max = ( arr[j] > arr[max] ) ? j : max;
             // cделаем перестановку этого элемента, поменяв его местами с текущим
             if (i != max)
             {
             buf = arr[i];
             arr[i] = arr[max];
             arr[max] = buf;
             }
             }
               for (int i = 0; i < N; i++) //Вывод отсортированного массива
             cout << arr[i] << ' ';
             cout << endl; //вывод массива
}
    }
// *******************************************************

	//Задание 6. 
	//Объявите встроенный одномерный массив, состоящий из N элементов целого типа. 
	//Напишите фрагмент кода, который вводит целые числа с помощью
	//потока ввода в объявленный Вами массив, каждый раз ( на каждой итерации!)
	//упорядочивая полученное значение по возрастанию.
	//Для проверки выводите массив на консоль на каждой итерации`
    {const int N=10;
           int arr[N];
           for (int i = 0; i < N; i++)
           {
               cin >> arr[i];
               for (int k = 0; k < i; k++)
               {
                   for (int j = i; j > k; --j)
                   {
                       if(arr[j] < arr[j - 1])
                       {
                           int tmp = arr[j];
                           arr[j]=arr[j - 1];
                           arr[j - 1] = tmp;
                       }
                   }
               }//            min = i;           // запомним номер текущей ячейки, как ячейки с минимальным значением
               //            // в цикле найдем реальный номер ячейки с максимальным значением
               //            for (int j = i + 1; j < N; j++)
               //                min = (arr[j] > arr[min] ) ? j : min;
               //            // cделаем перестановку этого элемента, поменяв его местами с текущим
               //            if (i != min)
               //            {
               //                buf = arr[i];
               //                arr[i] = arr[min];
               //                arr[min] = buf;


                          }
               for (int i = 0; i < N; i++) //Вывод отсортированного массива
                   cout << arr[i] << ' ';
               cout << endl;
    }
// *******************************************************
	//Задание 7. 

	//Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:
	//очередное введенное значение помещается в массив только при условии, 
	//что там еще такого нет (то есть дубли игнорируются)
              {
        const int N=10;
                      int arr[N];
                      for (int i = 0; i < N; i++)
                      {
                          cin >> arr[i];
                          for (int k = 0; k < i; k++)
                          {
                              for (int j = i; j > k; --j)
                              {
                                  if(arr[j] < arr[j - 1])
                                  {
                                      int tmp = arr[j];
                                      arr[j]=arr[j - 1];
                                      arr[j - 1] = tmp;
                                  }
                              }
                          }
                      }
                       for (int i = 0; i < N; i++) //Вывод отсортированного массива
                       cout << arr[i] << ' ';
                          cout << endl;
     }

// *******************************************************
	//Задание 8
	//Объявите одномерный встроенный массив элементов типа char.
	//Сформируйте значения элементов массива с помощью генератора случайных 
	//чисел таким образом, чтобы в массиве были только символы '*' и '_'  
	
	//"сдвиньте звездочки" в начало массива, например:
	//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
	//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
	//и распечатайте массив 
//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)

    {const int N=10;
    srand(time(0));
    int arr[N];
    for (int i= 0; i<10; i++)
    {
        int v = rand() % 2;   // v1 в диапазоне 0 - 1
        v=arr[i];
        //v==1 ? arr[i] = '_' : arr[i] = '*';
        cout << ((arr[i] == 1) ? arr[i] = '_' : arr[i] = '*');
      }
    }
// *******************************************************
	//Задание 9
	//объявите одномерный встроенный массив  из N элементов и проинициализируйте его.
    const int N=7;
    uint ar [N] {5,2,11,4,23,9,0};
    size_t m=sizeof (ar)/sizeof (ar[0]);                            //а) сдвиньте все элементы массива вправо на 1 позицию
    {for (int i=m-1; i>0;--i) {
    ar[i]=ar[i-1];
    cout << ar[i]; }}

        //б) (Циклическая перестановка). Сдвиньте все элементы массива вправо на 1 позицию ,
	//но последний элемент не должен быть утерян. Его следут переместить в начало.
	//например,  { 5, 2, 11, 4, 23, 9 } ->  {9, 5, 2, 11, 4, 23 }
    int tmp=ar[m-1];
    for (int i=m-1; i>0;--i) {
        ar[i]=ar[i-1];}
        ar[0]=tmp;
    for (int i=0; i<m-1;++i){
        cout << ar[i]<<' ';}
        cout << endl;
	//в)(Кольцевой буфер) выведите массив на печать, циклически "сдвинув" элементы вправо на 1 позицию.
	//При решении задачи не следует перемещать элементы массива, а надо использовать кольцевой буфер.
	// Одномерный массив можно "свернуть" в кольцо и считать, что за последним элементом следует начальный и
	// потом установить "новое" начало массива.

// *******************************************************
	//Задание 10 (*)
	//алгоритм "тасования колоды"
	//объявите одномерный встроенный массив  из N элементов и 
	// заполните  его неповторяющимися числами из заданного отрезка 
	//натурального ряда, расположенными в случайном порядке
//(Подсказки в файле Алгоритмы для лабораторной работы_4.pdf)
//Алгоритм:
//Массив  A [N] инициализируется последовательными значениями из отрезка, например [0,N-1]
//index=N-1, где index- максимальное значение индекса.

//В цикле по index выполняется перемешивание значений:
//	1. Генерируется случайное число  R из отрезка [0, index]
//	2. Выполняется обмен значений A[index]  и  A[R]
//	3. index=index -1
//	4. Если index==0, то конец
//	5. Переход к шагу 1    

	//Для того, чтобы выполнять это задание было интереснее, можно воспользоваться следующим массивом
	// массив текстовых эквивалентов  достоинства карт
const char* cards[] = { " 2\5", " 3\5", " 4\5", " 5\5", " 6\5", " 7\5", " 8\5", " 9\5", "10\5", " J\5", " Q\5", " K\5", " A\5",
	" 2\4", " 3\4", " 4\4", " 5\4", " 6\4", " 7\4", " 8\4", " 9\4", "10\4", " J\4", " Q\4", " K\4", " A\4",
	" 2\3", " 3\3", " 4\3", " 5\3", " 6\3", " 7\3", " 8\3", " 9\3", "10\3", " J\3", " Q\3", " K\3", " A\3",
	" 2\6", " 3\6", " 4\6", " 5\6", " 6\6", " 7\6", " 8\6", " 9\6", "10\6", " J\6", " Q\6", " K\6", " A\6",
};

// *******************************************************

}
