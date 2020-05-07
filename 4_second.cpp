#include <iostream>		//для работы с cout, cin
#include <string>		//для конвертации типов данных
#include <sys/wait.h>	//для работы функции ожидания процесса
#include <sys/types.h>	
#include <stdlib.h>		//для работы atoi()
#include <unistd.h>		//для работы exec()

using namespace std;

int main(){
	unsigned int nachalo_intervala, konec_intervala, kolvo_chastey, first_number, second_number;	//объявление переменнных
	cout<<"Введите начало интервала: ";
	cin>>nachalo_intervala;
	cout<<"Введите конец интервала: ";
	cin>>konec_intervala;
	cout<<"Введите количество частей: ";
	cin>>kolvo_chastey;

	if((nachalo_intervala > 0) && (konec_intervala > 0)){	//все введено верно
		// проверка: длина интервала больше количества частей
		if(konec_intervala - nachalo_intervala + 1 > kolvo_chastey){
			// проверка: делится ли длина интервала на количество частей нацело
			if((konec_intervala - nachalo_intervala + 1) % kolvo_chastey == 0){	//если остаток от деления длины интервала на кол-во частей равен нулю - значит делится нацело
				//			
				for(int i = 0; i < kolvo_chastey; i++){
					first_number = nachalo_intervala + i * ((konec_intervala - nachalo_intervala + 1)/kolvo_chastey);
					second_number = nachalo_intervala + (i + 1) * ((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) - 1;
					
					pid_t pr = fork();
					int status;
					if(pr < 0){									//если не удалось создать процесс
						perror("Ошибка: Не удалось создать процесс.");
						exit(1);
					}
					else if(pr == 0){							//если создание процесса завершилось удачей
						string aaa = (std::to_string(first_number)); 	//временные переменные
						string bbb = (std::to_string(second_number));	//временные переменные
						//создание массива аргументов, для передачи процессу
						char* const args[] = {"4first", (char*)(std::to_string(first_number)).c_str(), (char*)(std::to_string(second_number)).c_str(), NULL};

						execv(args[0], args);							//выполнение процесса и передача ему аргументов
					}
					wait(&status);										//ждем завершения процесса
				}
			}
			else {	//иначе - делится с остатком... значит последний интервал будет не полным
				for(int i=0; i < kolvo_chastey; i++){
					first_number = nachalo_intervala + i * (((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) + 1);
					if(i != kolvo_chastey-1)					//если не последний фрагмент интервала
						second_number = nachalo_intervala + (i + 1) * (((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) + 1) - 1;
					else										//если последний фрагмент интервала - второе число равно концу интервала
						second_number = konec_intervala;

					pid_t pr = fork();
					int status;
					if(pr < 0){									//если не удалось создать процесс
						perror("Ошибка: Не удалось создать процесс.");
						exit(1);
					}
					else if(pr == 0){							//если создание процесса завершилось удачей
						string aaa = (std::to_string(first_number)); 	//временные переменные
						string bbb = (std::to_string(second_number));	//временные переменные
						//создание массива аргументов, для передачи процессу
						char* const args[] = {"4first", (char*)(std::to_string(first_number)).c_str(), (char*)(std::to_string(second_number)).c_str(), NULL};

						execv(args[0], args);							//выполнение процесса и передача ему аргументов				
					}
					wait(&status);										//ждем завершения процесса
				}
			}
		}
		else
			cout<<"Ошибка: Нельзя интервал длиной "<<konec_intervala - nachalo_intervala + 1<<" разбить на "<<kolvo_chastey<<" частей! Программа завершается."<<endl;
	}
	else
		cout<<"Ошибка: Введены числа, не относящиеся к простым. Попробуйте заново. Программа завершается."<<endl;
	return 0;
}