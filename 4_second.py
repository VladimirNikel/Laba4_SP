import sys									#подключение библиотеки для работы с аргументами из терминала
import subprocess							#подключение библиотеки для работы с процессами

#тело программы
nachalo_intervala	= int(input("Введите начало интервала: "))			#ввод значений типа int
konec_intervala		= int(input("Введите конец интервала: "))			#ввод значений типа int
kolvo_chastey 		= int(input("Введите количество частей: "))			#ввод значений типа int

if(nachalo_intervala > 0) and (konec_intervala > 0) and (kolvo_chastey > 0):	#проверка на корректность данных
	#проверка: длина интервала больше количества частей
	if (konec_intervala - nachalo_intervala + 1) > kolvo_chastey:
		#проверка: делится ли длина на количество частей нацело (без остатка)
		if (konec_intervala - nachalo_intervala + 1) % kolvo_chastey == 0:
			for i in range(0, kolvo_chastey, 1):
				first_number = nachalo_intervala + i * (int)((konec_intervala - nachalo_intervala + 1)/kolvo_chastey)
				second_number = nachalo_intervala + (i + 1) * (int)((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) - 1
				command = [sys.executable, "./4_first.py", (str)(first_number), (str)(second_number)]		#формирование аргументов для передачи процессу
				pipe = subprocess.Popen(command, stdin=subprocess.PIPE)										#выполнение процесса		
				pipe.wait()												#ждем завершения процесса
		#иначе - делится с остатком
		else:
			for i in range(0, kolvo_chastey, 1):
				first_number = nachalo_intervala + i * ((int)((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) + 1)
				if not i == (kolvo_chastey - 1):						#если не последний фрагмент интервала
					second_number = nachalo_intervala + (i + 1) * ((int)((konec_intervala - nachalo_intervala + 1)/kolvo_chastey) + 1) - 1
				else:													#если последний фрагмент интервала - второе число равно концу интервала
					second_number = konec_intervala;

				command = [sys.executable, "./4_first.py", (str)(first_number), (str)(second_number)]		#формирование аргументов для передачи процессу
				pipe = subprocess.Popen(command, stdin=subprocess.PIPE)
				pipe.wait()												#ждем завершения процесса
	else:
		print("Ошибка: Нельзя интервал длиной ",konec_interava - nachalo_intervala + 1, " разбить на ", kolvo_chastey, " частей." )
else:
	print("Ошибка: Введены некорректные данные. Программа завершается.")