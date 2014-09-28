CREATE DATABASE mProject

CREATE TABLE Students(
	id INT IDENTITY PRIMARY KEY,
	full_name NVARCHAR (45) NOT NULL,
	gr_number SMALLINT
)

 -- считаем, что если у предмета существует и практика и экзамен и это находится в 1 записи,
 -- то для групп экзамен и зачет атомарны (обязательны сразу оба). В таблице могут находится значения id name 0 1 тогда считается,
 -- что существует только практика, и наоборот 1 0 - только экзамен

CREATE TABLE Exams(
	id INT IDENTITY PRIMARY KEY,
	university_subject NVARCHAR(40)
)

CREATE TABLE Practise_exams(
	id INT IDENTITY PRIMARY KEY,
	university_subject NVARCHAR(40)
)

--не самое лучший выбор хранения информации, но зато компактный, а вывод в красивом варианте можо получить запросами
--сюда данные вносятся руками
--если название предмета и практики совпадает то данные вносятся в 1 строку
CREATE TABLE Group_duty( 
	gr_number SMALLINT,
	compulsory_exam INT REFERENCES Exams(id) NULL, 
	compulsory_practise_exam INT REFERENCES Practise_exams(id) NULL
)

CREATE TABLE Exams_requirements(
	exam_id INT REFERENCES Exams(id),
	practise_for_exam INT REFERENCES Practise_exams(id)
)

CREATE TABLE Exam_progress(
	st_id INT REFERENCES Students(id),
	exam_id INT REFERENCES Exams(id),
	exam NVARCHAR(12), CHECK (exam IN (N'сдал', N'не сдал', N'справка', N'нет допуска'))
)

CREATE TABLE Practise_progress(
	st_id INT REFERENCES Students(id),
	practise_id INT REFERENCES Practise_exams(id),
	practise NVARCHAR(12), CHECK (practise IN (N'зачет', N'незачет', N'справка'))
)
