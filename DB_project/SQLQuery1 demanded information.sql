 --��� �� ������������ ������ �������� � ��� ��� ����� �������, ��� �����, ��� ��������
 CREATE FUNCTION f1_1( --��� ����� �������
	@id INT
 )RETURNS @table TABLE (������� NVARCHAR(40), ����� NVARCHAR(40)) 
 AS
 BEGIN
	DECLARE @gr_number SMALLINT = (SELECT gr_number FROM Students WHERE @id = id)
	DECLARE @tmpTable TABLE (id INT, ex INT, pr INT); 
	INSERT INTO @tmpTable SELECT * FROM Group_duty WHERE gr_number = @gr_number
	INSERT INTO @table SELECT * 
		FROM (SELECT university_subject FROM @tmpTable JOIN Exams ON Exams.id = ex) a FULL OUTER JOIN
			(SELECT university_subject FROM @tmpTable JOIN Practise_exams ON Practise_exams.id = pr) b
				ON a.university_subject = b.university_subject
	RETURN
 END

 CREATE FUNCTION f1_2( --��� �����
	@id INT
 )RETURNS @table TABLE (������� NVARCHAR(40), ����� NVARCHAR(40)) 
 AS
 BEGIN
	DECLARE @tmpTable TABLE (st_id INT,	exam_id INT, exam NVARCHAR(12)); 
	DECLARE @tmpTable2 TABLE (st_id INT, practise_id INT, practise NVARCHAR(12)); 
	INSERT INTO @tmpTable SELECT * FROM Exam_progress WHERE st_id = @id and exam = N'����'
	INSERT INTO @tmpTable2 SELECT * FROM Practise_progress WHERE st_id = @id and practise = N'�����'
	INSERT INTO @table SELECT * 
		FROM (SELECT university_subject FROM @tmpTable JOIN Exams ON Exams.id = exam_id) a FULL OUTER JOIN
			(SELECT university_subject FROM @tmpTable2 JOIN Practise_exams ON Practise_exams.id = practise_id) b
				ON a.university_subject = b.university_subject
	RETURN
 END

 CREATE FUNCTION f1_3( --��� �������� : ���� � ������� ��������� �� �������� � �.�. ��� �����, ��� ��� �� ������� ������.
	@id INT
 )RETURNS @table TABLE (������� NVARCHAR(40), ����� NVARCHAR(40)) 
 AS
 BEGIN
	INSERT INTO @table  SELECT * FROM f1_1(@id) EXCEPT SELECT * FROM f1_2(@id)
	RETURN
 END


 CREATE FUNCTION f2_1( --�������� �� ��������
	@cource NVARCHAR(40)
 )RETURNS @table TABLE (st_name NVARCHAR(45))
 AS
 BEGIN
	DECLARE @ex_id INT = (SELECT id FROM Exams WHERE Exams.university_subject = @cource)
	INSERT INTO @table SELECT full_name FROM Students
			WHERE
				gr_number in (SELECT gr_number FROM Group_duty WHERE compulsory_exam = @ex_id GROUP BY gr_number)  
					AND (SELECT COUNT(*) FROM Exam_progress WHERE st_id = id AND exam = N'����' AND exam_id = @ex_id) = 0 
	RETURN
 END

  CREATE FUNCTION f2_2( --�������� �� �������
	@cource NVARCHAR(40)
 )RETURNS @table TABLE (st_name NVARCHAR(45))
 AS
 BEGIN
	DECLARE @ex_id INT = (SELECT id FROM Practise_exams WHERE university_subject = @cource)
	INSERT INTO @table SELECT full_name FROM Students
			WHERE
				gr_number in (SELECT gr_number FROM Group_duty WHERE compulsory_practise_exam = @ex_id GROUP BY gr_number)  
					AND (SELECT COUNT(*) FROM Practise_progress WHERE st_id = id AND practise = N'�����' AND practise_id = @ex_id) = 0 
	RETURN
 END

 CREATE FUNCTION f3_1( --������� � � ������
	@n INT
 ) RETURNS @table TABLE (st_name NVARCHAR(45))
 AS
 BEGIN
	INSERT INTO @table SELECT full_name FROM Students
		WHERE (SELECT COUNT(�����) FROM f1_3(id) WHERE ����� IS NOT NULL) 
			+ (SELECT COUNT(�������) FROM f1_3(id) WHERE ������� IS NOT NULL) = @n
 RETURN
 END


select * from f1_1(1)
select * from f1_1(16)

select * from f1_2(1)
select * from f1_2(2)

select * from f1_3(3)

SELECT * FROM f2_1(N'���')
SELECT * FROM f2_2(N'����������')

SELECT * FROM f3_1(0)
SELECT * FROM f3_1(4)