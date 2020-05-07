#include <iostream>		//для работы с cout, cin
#include <stdlib.h>		//для работы atoi()
#include <cmath>		//для sqrt()
#include <unistd.h>		//для getpid()

using namespace std;

bool prime (unsigned int x){								//алгоритм определения числа на принадлежность к простым числам
	for(unsigned int i=2; i<=sqrt(x); i++)
		if(x%i == 0)
			return false;
		return true;
}

int main(int argc, char *argv[]){	
	unsigned int 	nachalo_intervala,	konec_intervala;	//объявление переменнных

	cout<<"\t"<<argv[0]<<"\tPID: "<<getpid()<<endl;			//вывод id процесса

	if(atoi(argv[1])>1 && atoi(argv[2])>atoi(argv[1])){		//обработка входных данных - если всё ок, то выполняем
		nachalo_intervala =	atoi(argv[1]);					//первое переданное значение - начало интервала
		konec_intervala   =	atoi(argv[2]);					//второе переданное значение - конец интервала

		cout<<"В интервале от "<<nachalo_intervala<<" до "<<konec_intervala<<" простые числа:"<<endl;
		for (unsigned int i=nachalo_intervala; i<=konec_intervala; i++){		//перебор всех чисел внутри введенного интервала
			if(prime(i) == true)
				cout<<i<<endl;
		}
	}
	else{													//если поступили некорректные данные
		cout<<"Ошибка: Введены некорректные данные. Программа завершается."<<endl;
		return 1;
	}
	
	return 0;
}