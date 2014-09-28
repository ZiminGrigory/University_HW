--������� ���� ��������� �� ����� ������ ���������� �� ���.
SELECT full_name FROM Students WHERE gr_number = 245 ORDER BY full_name

--����������� ������� ���-���� �������� �� ����� �������.

SELECT university_subject FROM (SELECT Exam_progress.exam_id FROM Exam_progress WHERE exam = N'����' ) s 
	JOIN Exams ON Exams.id = s.exam_id GROUP BY university_subject ORDER BY COUNT(university_subject) DESC 

--������ ����� ���������, �� ���������� �� ������ ������?

SELECT COUNT(*) FROM (SELECT id FROM Students EXCEPT SELECT st_id FROM Practise_progress WHERE practise = N'�����') s

--����� ����� ������������� ������
SELECT TOP(1) gr_number FROM Students GROUP BY gr_number ORDER BY COUNT(gr_number)

--����� ��������, �������� ������ ���� ���������

SELECT full_name FROM Students JOIN (SELECT TOP(1) st_id FROM Exam_progress WHERE exam = N'����' GROUP BY st_id ORDER BY COUNT(st_id) DESC) s ON s.st_id = id

--����� ���� ���������, ������� ��� ������������ �������� � ���� �� ����� ��������� �������

SELECT Students.id FROM Students 
	WHERE ((SELECT COUNT(st_id) FROM Practise_progress WHERE st_id = id and practise != N'�����')!=0
		OR Students.id not in (SELECT st_id FROM Practise_progress))
	AND (SELECT COUNT(*) FROM (SELECT ������� FROM f1_1(Students.id) EXCEPT SELECT ������� FROM f1_2(Students.id) ) s)  = 0


--����� ������ � ����� ������� ��������� (������ ������� � ���������).
SELECT top(1) a.gr_number, (a.m_count + b.m_count) as m_count FROM 
	(SELECT gr_number, COUNT(gr_number) as m_count FROM Group_duty WHERE compulsory_exam IS NOT NULL GROUP BY gr_number) a JOIN
	(SELECT gr_number, COUNT(gr_number) as m_count FROM Group_duty WHERE compulsory_practise_exam IS NOT NULL GROUP BY gr_number) b 
		ON a.gr_number = b.gr_number

--�����, ������� ��������� �� �������� (�.�., �� �������� ����������� �������) ���� �� � ������ ������������� ��������.
SELECT COUNT(id) FROM Students WHERE ((SELECT COUNT(�����) FROM f1_3(Students.id)) >= 3 )
	OR ((SELECT COUNT(*) FROM f1_3(Students.id) s WHERE s.����� IS NOT NULL AND s.������� IS NOT NULL) != 0)

--����� ����� �������� ������� (� ������������ ��������� �� �������). ��������� �������������� �������� �� �������������.

SELECT Exams.university_subject FROM
	(SELECT TOP(1) c.compulsory_exam, CAST(CAST(c.grCount - d.mGr_count AS FLOAT)/c.grCount AS FLOAT) AS not_passed_count FROM
	(SELECT compulsory_exam, SUM(gr_count) as grCount FROM 
		(SELECT gr_number, compulsory_exam FROM Group_duty WHERE compulsory_exam IS NOT NULL) a JOIN
		(SELECT gr_number, COUNT(id) AS gr_count FROM Students GROUP BY gr_number) b ON a.gr_number = b.gr_number 
	GROUP BY compulsory_exam ) c
	JOIN
	(SELECT exam_id, COUNT(st_id) as mGr_count FROM Exam_progress WHERE exam = N'����' GROUP BY exam_id) d ON c.compulsory_exam = d.exam_id
	ORDER BY not_passed_count DESC) t
JOIN
	Exams ON  Exams.id = compulsory_exam

--������, ��� ���� 1 ������� ���� ���� �������.



--���������, ���� �� � ���� �������, �� ���������� �� � ������ ������������� ��� ��� ������ ��������. 
--����� �������, ��� ������ ������ ������� ������� ���� �� ���� �������.

SELECT id FROM Students WHERE ((SELECT COUNT(�����) FROM f1_3(Students.id)) >= 3 ) 
	OR (SELECT COUNT(*) FROM f1_1(Students.id) s WHERE s.����� IS NOT NULL) 
		- (SELECT COUNT(*) FROM f1_2(Students.id) s WHERE s.����� IS NOT NULL) =0 



-- � ��������� �������� ������������ ���������� �������, ��.. �.�. ��� ������� ������ �� ���� = �������, �� ��� ������������� ����,
--������ ���������� �����