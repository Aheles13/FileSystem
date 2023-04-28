#include <iostream>
#include <fstream>// Библиотека позволяющая взаимодействовать с файловой системой компютера.
#include <string>

//ofstream - запись данных в файлы 
//ifstream - чтение данных из файла
//fstream - запись и чтенние данных из файла 

//Задача 1.

bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	return false;
}


bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);

	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;

}

bool statistic(std::string word);




int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";

	// Класс ofstream.
	std::ofstream out;               // Объект класса ofstream для запси данных файла
	//ИЛИ std::ofstream out(path);
	out.open(path, std::ios::app); // Открытие файла в режиме app

	if (out.is_open()) { // Проверка файла на открнытие
		std::cout << "Файл открыт для записи!\n";
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // Добавление информации в файл
		std::cout << "Запись добавлена в файл!\n";
	}
	else
		std::cout << "Ошибка открытия файла!\n";

	//Возможные причины при открытие файла :
	//1. Неправильный синтаксис указания к пути файла;
	//2. Нет доступа к файлу;
	//3. Файл открыт другим объектом или приложением.

	out.close(); // Закрытие файла и отчистка объекта out 

	// Класс ifstream.
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Файл открыт для чтения!\n";
		std::cout << "Содержимое файла:\n";
		std::string file_text;

		//1 Способ. Посимвольное считывание.
		//char sym;
		//while (in.get(sym))
			//std::cout << sym; // Только вывод 
			//file_text += sym; // Вывод и сохрание строки 
		//std::cout << file_text << std::endl;


		//2 Cпособ. Пословное счтывание.
		//while (!in.eof()) {
			//std::string tmp;
			//in >> tmp;
			//file_text += tmp + "\n";
		//}
		//std::cout << file_text << std::endl;

		//3 Способ. Построчное считывани.
		std::string line;
		while (std::getline(in, line))
			file_text += line + "\n";
		std::cout << file_text << std::endl;

	}
	else
		std::cout << "Ошибка открытия файла!\n";

	//Возможные причины ошибок при открытие файлов:
	//1. Неправильный синтаксиси указания к пути файла;
	//2. Нет доступа к файлу;
	//3. Файла не существует.

	in.close();

	//Удаление файлов.
	if (remove(path.c_str()) == 0)
		std::cout << "Файл \"" << path << "\" удалён.\n";
	else
		std::cout << "Ошибка удаленния файла.\n";

	//Возможные причины ошибок при удаленние файлов:
	//1. Неправильный синтаксиси указания к пути файла;
	//2. Нет доступа к файлу;
	//3. Файла не существует;
	//4. Файл открыт.

	//Задача 1 - 2. Слова в файл.
	std::cout << "Задача 1.\n ";
	int action;


	do {

		std::cout << "Выберите действия:\n";
		std::cout << "1.Добавление статистики в файл\n";
		std::cout << "2.Вывод файла\n";
		std::cout << "3.Очистка файла\n";
		std::cout << "4.Завершение работы \n";
		std::cout << "Введите номер действия ->";
		std::cin >> action;


		std::string str1;
		switch (action) {
		case 1:
			std::cout << "Введите строку -> ";
			std::cin.ignore();
			std::getline(std::cin, str1);

			if (statistic(str1)) {
				std::cout << "Запись добавленна в файл!\n\n";
				
			}
			else
				std::cout << "Ошибка выполнения функции!\n\n";
			break;

		case 2:
			std::cout << "Содержимое файла:\n";
			print_file("stats.txt");
			break;


		case 3:
			clear_file("stats.txt");
			std::cout << "Файл очищен!";
			break;

		case 4:
			std::cout << "Программа завершина!";
			break;

		default:
			std::cout << "Ошибка ввода!\n\n";
		}


			
	} while (action != 4);



	return 0;
}

//Задача 1.
bool statistic(std::string word) {
	std::ofstream out;
	out.open("stats.txt", std::ios::app);

	if (out.is_open()) {
		out << word << " " << word.length() << '\n';
		out.close();
		return true;
	}
	return false;
}