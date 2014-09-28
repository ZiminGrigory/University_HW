CREATE DATABASE mProject

CREATE TABLE Students(
	id INT IDENTITY PRIMARY KEY,
	full_name NVARCHAR (45) NOT NULL,
	gr_number SMALLINT
)

 -- �������, ��� ���� � �������� ���������� � �������� � ������� � ��� ��������� � 1 ������,
 -- �� ��� ����� ������� � ����� �������� (����������� ����� ���). � ������� ����� ��������� �������� id name 0 1 ����� ���������,
 -- ��� ���������� ������ ��������, � �������� 1 0 - ������ �������

CREATE TABLE Exams(
	id INT IDENTITY PRIMARY KEY,
	university_subject NVARCHAR(40)
)

CREATE TABLE Practise_exams(
	id INT IDENTITY PRIMARY KEY,
	university_subject NVARCHAR(40)
)

--�� ����� ������ ����� �������� ����������, �� ���� ����������, � ����� � �������� �������� ���� �������� ���������
--���� ������ �������� ������
--���� �������� �������� � �������� ��������� �� ������ �������� � 1 ������
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
	exam NVARCHAR(12), CHECK (exam IN (N'����', N'�� ����', N'�������', N'��� �������'))
)

CREATE TABLE Practise_progress(
	st_id INT REFERENCES Students(id),
	practise_id INT REFERENCES Practise_exams(id),
	practise NVARCHAR(12), CHECK (practise IN (N'�����', N'�������', N'�������'))
)
