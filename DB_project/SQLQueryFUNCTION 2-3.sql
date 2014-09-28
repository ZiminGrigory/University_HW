/*2.      �������� ������� ��� �������� �������� �� ������ � ������. ������� ������ ������� ������� �� ���������
, ������� ���������� ����� ��������, ����� ������������� ������� � ���������. 
������� ���������: ����� �������� ������ ��������, ������ � ����� ������ ������.
 ������� ����� ���� ��������� �� ������ � ������, ���� ������� � ��������� 
 (���������� ������������ ��������� � ��������� ��� ����� ������ �� ��������� � ����������� ������������ ��������� � ��������� � ������)
  ���������� �� ����� 10% �� ������ ���������� ��������� � ��������� ����� ������. 
  ���� ������� ��������� ���� �����, ������ ���� ���������� ����������. */


CREATE FUNCTION f2 (
	@st_id INT,
	@fst_gr SMALLINT,
	@snd_gr SMALLINT
)
RETURNS @table TABLE (�������� NVARCHAR(40), ������ NVARCHAR(40))
BEGIN
	DECLARE @oldGroup TABLE (�������� NVARCHAR(40), ������ NVARCHAR(40));
	DECLARE @newGroup TABLE (�������� NVARCHAR(40), ������ NVARCHAR(40));
	
	DECLARE @tmpTable TABLE (id INT, ex INT, pr INT); 
	INSERT INTO @tmpTable SELECT * FROM Group_duty WHERE gr_number = @fst_gr
	INSERT INTO @oldGroup SELECT * 
		FROM (SELECT university_subject FROM @tmpTable JOIN Exams ON Exams.id = ex) a FULL OUTER JOIN
			(SELECT university_subject FROM @tmpTable JOIN Practise_exams ON Practise_exams.id = pr) b
				ON a.university_subject = b.university_subject
	

	DECLARE @tmpTable2 TABLE (id INT, ex INT, pr INT); 
	INSERT INTO @tmpTable2 SELECT * FROM Group_duty WHERE gr_number = @snd_gr
	INSERT INTO @newGroup SELECT * 
		FROM (SELECT university_subject FROM @tmpTable2 JOIN Exams ON Exams.id = ex) a FULL OUTER JOIN
			(SELECT university_subject FROM @tmpTable2 JOIN Practise_exams ON Practise_exams.id = pr) b
				ON a.university_subject = b.university_subject

	DECLARE @common_count_in_new INT 
		= (SELECT COUNT(������) FROM @newGroup WHERE ������ IS NOT NULL)
			+ (SELECT COUNT(��������) FROM @newGroup WHERE �������� IS NOT NULL)
	
	DECLARE @difference INT =
		(SELECT COUNT(a.������) FROM 
			(SELECT ������ FROM @newGroup WHERE ������ IS NOT NULL EXCEPT SELECT ������ FROM @oldGroup WHERE ������ IS NOT NULL) a)
		+ (SELECT COUNT(b.��������) FROM 
			(SELECT �������� FROM @newGroup WHERE ������ IS NOT NULL EXCEPT SELECT �������� FROM @oldGroup WHERE ������ IS NOT NULL) b)

	IF CAST(CAST ( @difference AS FLOAT) / CAST(@common_count_in_new AS FLOAT) AS FLOAT) > 0.1 
		--��� �� ������ ����������, �� � �������� ����� �����
		DECLARE @fakeERROR INT = CAST(N'������� ��������� 10%, ������� ����������' as int) 
	
	INSERT INTO @table SELECT * 
		FROM (SELECT �������� FROM @newGroup WHERE ������ IS NOT NULL EXCEPT SELECT �������� FROM @oldGroup WHERE ������ IS NOT NULL) a
		 FULL OUTER JOIN
		 (SELECT ������ FROM @newGroup WHERE ������ IS NOT NULL EXCEPT SELECT ������ FROM @oldGroup WHERE ������ IS NOT NULL) b
				ON a.�������� = b.������ WHERE (������ IS NOT NULL AND �������� IS NOT NULL) OR (������ IS NOT NULL) OR (�������� IS NOT NULL)
	RETURN
END

SELECT * FROM f2(12, 123, 245)

--���������� �������� � ������, ����� ������ ������� 
INSERT Students VALUES (N'������� �������� ����������', 145)

INSERT Group_duty VALUES (145, 1, 1)
INSERT Group_duty VALUES (145, 18, 24)
INSERT Group_duty VALUES (145, 3, 9)
INSERT Group_duty VALUES (145, 7, 13)
INSERT Group_duty VALUES (145, 2, NULL)
INSERT Group_duty VALUES (145, NULL, 8)

SELECT * FROM f2(12, 123, 145)

/*3. �������� ��������� ��� �������� ���� ���������, ������� ������� ��� ������������ �������� �� ��������� ����. 
������� ���������: ������� ����� ������, ����� ������ �� ��������� �����. �������� ��������: ���������� ������������ ���������.*/

CREATE PROCEDURE P3 (
	@old_number SMALLINT,
	@new_number SMALLINT,
	@res int OUTPUT
) AS
BEGIN
	DECLARE @tmp_table TABLE (id INT);
	INSERT INTO @tmp_table SELECT * FROM (SELECT id FROM Students WHERE (SELECT COUNT(*) FROM f1_3(id) s) = 0 AND gr_number = @old_number) s
	SET @res = (SELECT COUNT(*) FROM @tmp_table)
	UPDATE Students 
	SET gr_number = @new_number WHERE (SELECT COUNT(id) FROM @tmp_table WHERE Students.id = id) = 1
	RETURN
END

UPDATE Students SET gr_number = 352 FROM Students WHERE gr_number = 353

DECLARE @res INT
EXEC p3 352, 353, @res OUTPUT
SELECT @res

SELECT * FROM Students WHERE gr_number = 353