INSERT Students VALUES (N'������� ������� ���������', 123)
INSERT Students VALUES (N'���������� ������� �������������', 123)
INSERT Students VALUES (N'������� ������ ����������', 123)
INSERT Students VALUES (N'���������� ��������� ����������', 123)
INSERT Students VALUES (N'�������� ������� ���������', 123)
INSERT Students VALUES (N'�������� ������ ����������', 123)
INSERT Students VALUES (N'������� ��������� �����������', 123)
INSERT Students VALUES (N'������������ ����� ������������', 123)
INSERT Students VALUES (N'����� �������� �����������', 123)
INSERT Students VALUES (N'������ ����� ����������', 123)
INSERT Students VALUES (N'������� ������� ��������', 123)
INSERT Students VALUES (N'������� �������� ����������', 123)
INSERT Students VALUES (N'����� ���� ����������', 123)
INSERT Students VALUES (N'������ ϸ�� ����������', 123)
INSERT Students VALUES (N'������ ������� ����������', 123)

INSERT Students VALUES (N'��������� ����� �����������', 245)
INSERT Students VALUES (N'������ ������� ����������', 245)
INSERT Students VALUES (N'��������� ������� ����������', 245)
INSERT Students VALUES (N'������� ������� ��������', 245)
INSERT Students VALUES (N'��������� ������� ����������', 245)
INSERT Students VALUES (N'������� ������� �����������', 245)
INSERT Students VALUES (N'������� �������� ��������', 245)
INSERT Students VALUES (N'�������� ���� �������������', 245)
INSERT Students VALUES (N'������� ����� ����������', 245)
INSERT Students VALUES (N'����� ������ ����������', 245)
INSERT Students VALUES (N'������� ������� �����������', 245)
INSERT Students VALUES (N'������ ������ �����������', 245)
INSERT Students VALUES (N'������� ��������� ����������', 245)
INSERT Students VALUES (N'������� ���� ����������', 245)
INSERT Students VALUES (N'������ ���� �����������', 245)
INSERT Students VALUES (N'������� ������� ����������', 245)

INSERT Students VALUES (N'������� ������� ����������', 563)
INSERT Students VALUES (N'������ ���� �������������', 563)
INSERT Students VALUES (N'����� ������ ������������', 563)
INSERT Students VALUES (N'�������� �������� ����������', 563)
INSERT Students VALUES (N'��������� ���� ��������', 563)
INSERT Students VALUES (N'������� ������ ��������', 563)


INSERT Students VALUES (N'�������� ������ ������������', 352)
INSERT Students VALUES (N'�������� ���� ����������', 352)
INSERT Students VALUES (N'������� ������� �����������', 352)



SELECT * FROM Students

--�������� �� ���������� ��������
CREATE PROCEDURE firstFunction 
(
	@parameter_exam NVARCHAR(20) = '',
	@parameter_practise NVARCHAR(20) = '',
	@res int OUTPUT
) 
AS
BEGIN
	DECLARE @flag1 BIT = 0;
	IF @parameter_practise is not null
		IF (@parameter_practise not in (SELECT university_subject FROM Practise_exams))
			INSERT Practise_exams VALUES (@parameter_practise)

	IF @parameter_exam is not null
	BEGIN
		IF (@parameter_exam not in (SELECT university_subject FROM Exams))
			INSERT Exams VALUES (@parameter_exam)
		ELSE 
			SET @flag1 = 1
	END ELSE SET @flag1 = 1

	DECLARE @id_ex INT = (SELECT id FROM Exams WHERE university_subject = @parameter_exam) 
	DECLARE @id_pr INT = (SELECT id FROM Practise_exams WHERE university_subject = @parameter_practise)
	
	IF (@parameter_practise is not null) AND (@parameter_exam is not null)
		IF (SELECT COUNT(*) FROM Exams_requirements WHERE exam_id = @id_ex and practise_for_exam = @id_pr) = 0
			INSERT Exams_requirements VALUES (@id_ex, @id_pr)

	IF @flag1 = 1 
		SET @res = -1
	ELSE
		SET @res = @id_ex
	RETURN
END


--���������� ���������
DECLARE @res INT
EXEC firstFunction NULL, N'�����', @res OUTPUT
SELECT @res

DECLARE @res INT
EXEC firstFunction NULL, N'����������� ���', @res OUTPUT
EXEC firstFunction NULL, N'������������ ������� � ��������', @res OUTPUT
EXEC firstFunction NULL, N'�������', @res OUTPUT
EXEC firstFunction NULL, N'������������ ���������', @res OUTPUT
EXEC firstFunction NULL, N'�����������', @res OUTPUT
EXEC firstFunction NULL, N'����������', @res OUTPUT

EXEC firstFunction N'���������� ����������',NULL, @res OUTPUT


EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'���', N'���', @res OUTPUT
EXEC firstFunction N'�������', N'�������', @res OUTPUT
EXEC firstFunction N'������', N'������', @res OUTPUT
EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'�����������', N'�����������', @res OUTPUT
EXEC firstFunction N'��', N'��', @res OUTPUT
EXEC firstFunction N'���������� ����', N'���������� ����', @res OUTPUT
EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'�������������� ������', N'�������������� ������', @res OUTPUT
EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'���������', N'���������', @res OUTPUT
EXEC firstFunction N'�����', N'�����', @res OUTPUT
EXEC firstFunction N'������', N'������', @res OUTPUT
EXEC firstFunction N'�������', N'�������', @res OUTPUT
EXEC firstFunction N'������������� ���������', N'������������� ���������', @res OUTPUT

--���������� ������������ ��� ������ ������� � ����������
INSERT Exams_requirements VALUES (15,16) --�������� ��� ����� ������������ ����� -���������
INSERT Exams_requirements VALUES (15,22)

--���������� ���������/������� ��� �����
INSERT Group_duty VALUES (123, 1, 1)
INSERT Group_duty VALUES (123, 18, 24)
INSERT Group_duty VALUES (123, 3, 9)
INSERT Group_duty VALUES (123, 7, 13)
INSERT Group_duty VALUES (123, 2, NULL)


INSERT Group_duty VALUES (245, 1, 1)
INSERT Group_duty VALUES (245, 4, 10)
INSERT Group_duty VALUES (245, 8, 14)
INSERT Group_duty VALUES (245, 9, 15)


INSERT Group_duty VALUES (563, NULL, 8)
INSERT Group_duty VALUES (563, 10, 16)


INSERT Group_duty VALUES (352, 11, 17)
INSERT Group_duty VALUES (352, 17, 23)
INSERT Group_duty VALUES (352, 9, 15)

--������� �������� � ������

INSERT Practise_progress VALUES(1, 1, N'�����'); INSERT Exam_progress VALUES(1, 1, N'����')
INSERT Practise_progress VALUES(2, 1, N'�������'); INSERT Exam_progress VALUES(2, 1, N'��� �������');
INSERT Practise_progress VALUES(3, 1, N'�����'); INSERT Exam_progress VALUES(3, 1, N'����');
INSERT Practise_progress VALUES(4, 1, N'�����'); INSERT Exam_progress VALUES(4, 1, N'����');
INSERT Practise_progress VALUES(5, 1, N'�������'); INSERT Exam_progress VALUES(5, 1, N'��� �������');
INSERT Practise_progress VALUES(6, 1, N'�����'); INSERT Exam_progress VALUES(6, 1, N'�� ����');
INSERT Practise_progress VALUES(7, 1, N'�������'); INSERT Exam_progress VALUES(7, 1, N'��� �������');
INSERT Practise_progress VALUES(8, 1, N'�����'); INSERT Exam_progress VALUES(8, 1, N'�� ����');
INSERT Practise_progress VALUES(9, 1, N'�����'); INSERT Exam_progress VALUES(9, 1, N'����');
INSERT Practise_progress VALUES(10, 1, N'�������'); INSERT Exam_progress VALUES(10, 1, N'��� �������');
INSERT Practise_progress VALUES(11, 1, N'�������'); INSERT Exam_progress VALUES(11, 1, N'��� �������');
INSERT Practise_progress VALUES(12, 1, N'�����'); INSERT Exam_progress VALUES(12, 1, N'����');
INSERT Practise_progress VALUES(13, 1, N'�������'); INSERT Exam_progress VALUES(13, 1, N'��� �������');
INSERT Practise_progress VALUES(14, 1, N'�����'); INSERT Exam_progress VALUES(14, 1, N'�� ����');
INSERT Practise_progress VALUES(15, 1, N'�����'); INSERT Exam_progress VALUES(15, 1, N'����');

INSERT Practise_progress VALUES(1, 24, N'�����'); INSERT Exam_progress VALUES(1, 18, N'����')
INSERT Practise_progress VALUES(2, 24, N'�����'); INSERT Exam_progress VALUES(2, 18, N'����')
INSERT Practise_progress VALUES(3, 24, N'�����'); INSERT Exam_progress VALUES(3, 18, N'����')
INSERT Practise_progress VALUES(4, 24, N'�����'); INSERT Exam_progress VALUES(4, 18, N'����')
INSERT Practise_progress VALUES(5, 24, N'�����'); INSERT Exam_progress VALUES(5, 18, N'����')
INSERT Practise_progress VALUES(6, 24, N'�����'); INSERT Exam_progress VALUES(6, 18, N'����')
INSERT Practise_progress VALUES(7, 24, N'�����'); INSERT Exam_progress VALUES(7, 18, N'�� ����')
INSERT Practise_progress VALUES(8, 24, N'�����'); INSERT Exam_progress VALUES(8, 18, N'����')
INSERT Practise_progress VALUES(9, 24, N'�����'); INSERT Exam_progress VALUES(9, 18, N'�� ����')
INSERT Practise_progress VALUES(10, 24, N'�����'); INSERT Exam_progress VALUES(10, 18, N'����')
INSERT Practise_progress VALUES(11, 24, N'�������'); INSERT Exam_progress VALUES(11, 18, N'��� �������')
INSERT Practise_progress VALUES(12, 24, N'�������'); INSERT Exam_progress VALUES(12, 18, N'��� �������')
INSERT Practise_progress VALUES(13, 24, N'�������'); INSERT Exam_progress VALUES(13, 18, N'��� �������')
INSERT Practise_progress VALUES(14, 24, N'�������'); INSERT Exam_progress VALUES(14, 18, N'��� �������')
INSERT Practise_progress VALUES(15, 24, N'�����'); INSERT Exam_progress VALUES(15, 18, N'����')

INSERT Practise_progress VALUES(1, 9, N'�����'); INSERT Exam_progress VALUES(1, 3, N'����')
INSERT Practise_progress VALUES(2, 9, N'�������'); INSERT Exam_progress VALUES(2, 3, N'��� �������')
INSERT Practise_progress VALUES(3, 9, N'�����'); INSERT Exam_progress VALUES(3, 3, N'����')
INSERT Practise_progress VALUES(4, 9, N'�������'); INSERT Exam_progress VALUES(4, 3, N'��� �������')
INSERT Practise_progress VALUES(5, 9, N'�����'); INSERT Exam_progress VALUES(5, 3, N'����')
INSERT Practise_progress VALUES(6, 9, N'�������'); INSERT Exam_progress VALUES(6, 3, N'��� �������')
INSERT Practise_progress VALUES(7, 9, N'�����'); INSERT Exam_progress VALUES(7, 3, N'����')
INSERT Practise_progress VALUES(8, 9, N'�������'); INSERT Exam_progress VALUES(8, 3, N'��� �������')
INSERT Practise_progress VALUES(9, 9, N'�����'); INSERT Exam_progress VALUES(9, 3, N'����')
INSERT Practise_progress VALUES(10, 9, N'�������'); INSERT Exam_progress VALUES(10, 3, N'��� �������')
INSERT Practise_progress VALUES(11, 9, N'�����'); INSERT Exam_progress VALUES(11, 3, N'����')
INSERT Practise_progress VALUES(12, 9, N'�������'); INSERT Exam_progress VALUES(12, 3, N'��� �������')
INSERT Practise_progress VALUES(13, 9, N'�������'); INSERT Exam_progress VALUES(13, 3, N'��� �������')
INSERT Practise_progress VALUES(14, 9, N'�������'); INSERT Exam_progress VALUES(14, 3, N'��� �������')
INSERT Practise_progress VALUES(15, 9, N'�������'); INSERT Exam_progress VALUES(15, 3, N'��� �������')

INSERT Practise_progress VALUES(1, 13, N'�����'); INSERT Exam_progress VALUES(1, 7, N'����')
INSERT Practise_progress VALUES(2, 13, N'�����'); INSERT Exam_progress VALUES(2, 7, N'����')
INSERT Practise_progress VALUES(3, 13, N'�������'); INSERT Exam_progress VALUES(3, 7, N'��� �������')
INSERT Practise_progress VALUES(4, 13, N'�������'); INSERT Exam_progress VALUES(4, 7, N'��� �������')
INSERT Practise_progress VALUES(5, 13, N'�����'); INSERT Exam_progress VALUES(5, 7, N'����')
INSERT Practise_progress VALUES(6, 13, N'�����'); INSERT Exam_progress VALUES(6, 7, N'����')
INSERT Practise_progress VALUES(7, 13, N'�����'); INSERT Exam_progress VALUES(7, 7, N'����')
INSERT Practise_progress VALUES(8, 13, N'�������'); INSERT Exam_progress VALUES(8, 7, N'��� �������')
INSERT Practise_progress VALUES(9, 13, N'�����'); INSERT Exam_progress VALUES(9, 7, N'����')
INSERT Practise_progress VALUES(10, 13, N'�����'); INSERT Exam_progress VALUES(10, 7, N'�� ����')
INSERT Practise_progress VALUES(11, 13, N'�����'); INSERT Exam_progress VALUES(11, 7, N'����')
INSERT Practise_progress VALUES(12, 13, N'�����'); INSERT Exam_progress VALUES(12, 7, N'����')
INSERT Practise_progress VALUES(13, 13, N'�����'); INSERT Exam_progress VALUES(13, 7, N'����')
INSERT Practise_progress VALUES(14, 13, N'�������'); INSERT Exam_progress VALUES(14, 7, N'��� �������')
INSERT Practise_progress VALUES(15, 13, N'�������'); INSERT Exam_progress VALUES(15, 7, N'��� �������')

INSERT Exam_progress VALUES(1, 2, N'����')
INSERT Exam_progress VALUES(2, 2, N'����')
INSERT Exam_progress VALUES(3, 2, N'����')
INSERT Exam_progress VALUES(4, 2, N'����')
INSERT Exam_progress VALUES(5, 2, N'����')
INSERT Exam_progress VALUES(6, 2, N'����')
INSERT Exam_progress VALUES(7, 2, N'����')
INSERT Exam_progress VALUES(8, 2, N'�� ����')
INSERT Exam_progress VALUES(9, 2, N'����')
INSERT Exam_progress VALUES(10, 2, N'�� ����')
INSERT Exam_progress VALUES(11, 2, N'����')
INSERT Exam_progress VALUES(12, 2, N'����')
INSERT Exam_progress VALUES(13, 2, N'�� ����')
INSERT Exam_progress VALUES(14, 2, N'����')
INSERT Exam_progress VALUES(15, 2, N'����')

INSERT Practise_progress VALUES(16, 1, N'�����'); INSERT Exam_progress VALUES(16, 1, N'����')
INSERT Practise_progress VALUES(17, 1, N'�������'); INSERT Exam_progress VALUES(17, 1, N'��� �������');
INSERT Practise_progress VALUES(18, 1, N'�����'); INSERT Exam_progress VALUES(18, 1, N'����');
INSERT Practise_progress VALUES(19, 1, N'�����'); INSERT Exam_progress VALUES(19, 1, N'����');
INSERT Practise_progress VALUES(20, 1, N'�������'); INSERT Exam_progress VALUES(20, 1, N'��� �������');
INSERT Practise_progress VALUES(21, 1, N'�����'); INSERT Exam_progress VALUES(21, 1, N'�� ����');
INSERT Practise_progress VALUES(22, 1, N'�������'); INSERT Exam_progress VALUES(22, 1, N'��� �������');
INSERT Practise_progress VALUES(23, 1, N'�����'); INSERT Exam_progress VALUES(23, 1, N'�� ����');
INSERT Practise_progress VALUES(24, 1, N'�����'); INSERT Exam_progress VALUES(24, 1, N'����');
INSERT Practise_progress VALUES(25, 1, N'�������'); INSERT Exam_progress VALUES(25, 1, N'��� �������');
INSERT Practise_progress VALUES(26, 1, N'�������'); INSERT Exam_progress VALUES(26, 1, N'��� �������');
INSERT Practise_progress VALUES(27, 1, N'�����'); INSERT Exam_progress VALUES(27, 1, N'����');
INSERT Practise_progress VALUES(28, 1, N'�������'); INSERT Exam_progress VALUES(28, 1, N'��� �������');
INSERT Practise_progress VALUES(29, 1, N'�����'); INSERT Exam_progress VALUES(29, 1, N'�� ����');
INSERT Practise_progress VALUES(30, 1, N'�����'); INSERT Exam_progress VALUES(30, 1, N'����');
INSERT Practise_progress VALUES(31, 1, N'�����'); INSERT Exam_progress VALUES(31, 1, N'����')

INSERT Practise_progress VALUES(16, 10, N'�����'); INSERT Exam_progress VALUES(16, 4, N'����')
INSERT Practise_progress VALUES(17, 10, N'�����'); INSERT Exam_progress VALUES(17, 4, N'����')
INSERT Practise_progress VALUES(18, 10, N'�����'); INSERT Exam_progress VALUES(18, 4, N'����')
INSERT Practise_progress VALUES(19, 10, N'�����'); INSERT Exam_progress VALUES(19, 4, N'����')
INSERT Practise_progress VALUES(20, 10, N'�����'); INSERT Exam_progress VALUES(20, 4, N'����')
INSERT Practise_progress VALUES(21, 10, N'�����'); INSERT Exam_progress VALUES(21, 4, N'����')
INSERT Practise_progress VALUES(22, 10, N'�����'); INSERT Exam_progress VALUES(22, 4, N'�� ����')
INSERT Practise_progress VALUES(23, 10, N'�����'); INSERT Exam_progress VALUES(23, 4, N'����')
INSERT Practise_progress VALUES(24, 10, N'�����'); INSERT Exam_progress VALUES(24, 4, N'�� ����')
INSERT Practise_progress VALUES(25, 10, N'�����'); INSERT Exam_progress VALUES(25, 4, N'����')
INSERT Practise_progress VALUES(26, 10, N'�������'); INSERT Exam_progress VALUES(26, 4, N'��� �������')
INSERT Practise_progress VALUES(27, 10, N'�������'); INSERT Exam_progress VALUES(27, 4, N'��� �������')
INSERT Practise_progress VALUES(28, 10, N'�������'); INSERT Exam_progress VALUES(28, 4, N'��� �������')
INSERT Practise_progress VALUES(29, 10, N'�������'); INSERT Exam_progress VALUES(29, 4, N'��� �������')
INSERT Practise_progress VALUES(30, 10, N'�����'); INSERT Exam_progress VALUES(30, 4, N'����')
INSERT Practise_progress VALUES(31, 10, N'�����'); INSERT Exam_progress VALUES(31, 4, N'����')

INSERT Practise_progress VALUES(16, 14, N'�����'); INSERT Exam_progress VALUES(16, 8, N'����')
INSERT Practise_progress VALUES(17, 14, N'�������'); INSERT Exam_progress VALUES(17, 8, N'��� �������')
INSERT Practise_progress VALUES(18, 14, N'�����'); INSERT Exam_progress VALUES(18, 8, N'����')
INSERT Practise_progress VALUES(19, 14, N'�������'); INSERT Exam_progress VALUES(19, 8, N'��� �������')
INSERT Practise_progress VALUES(20, 14, N'�����'); INSERT Exam_progress VALUES(20, 8, N'����')
INSERT Practise_progress VALUES(21, 14, N'�������'); INSERT Exam_progress VALUES(21, 8, N'��� �������')
INSERT Practise_progress VALUES(22, 14, N'�������'); INSERT Exam_progress VALUES(22, 8, N'��� �������')
INSERT Practise_progress VALUES(23, 14, N'�������'); INSERT Exam_progress VALUES(23, 8, N'��� �������')
INSERT Practise_progress VALUES(24, 14, N'�������'); INSERT Exam_progress VALUES(24, 8, N'��� �������')
INSERT Practise_progress VALUES(25, 14, N'�����'); INSERT Exam_progress VALUES(25, 8, N'����')
INSERT Practise_progress VALUES(26, 14, N'�������'); INSERT Exam_progress VALUES(26, 8, N'��� �������')
INSERT Practise_progress VALUES(27, 14, N'�����'); INSERT Exam_progress VALUES(27, 8, N'����')
INSERT Practise_progress VALUES(28, 14, N'�������'); INSERT Exam_progress VALUES(28, 8, N'��� �������')
INSERT Practise_progress VALUES(29, 14, N'�����'); INSERT Exam_progress VALUES(29, 8, N'����')
INSERT Practise_progress VALUES(30, 14, N'�������'); INSERT Exam_progress VALUES(30, 8, N'��� �������')
INSERT Practise_progress VALUES(31, 14, N'�����'); INSERT Exam_progress VALUES(31, 8, N'����')

INSERT Practise_progress VALUES(16, 15, N'�����'); INSERT Exam_progress VALUES(16, 9, N'����')
INSERT Practise_progress VALUES(17, 15, N'�����'); INSERT Exam_progress VALUES(17, 9, N'����')
INSERT Practise_progress VALUES(18, 15, N'�������'); INSERT Exam_progress VALUES(18, 9, N'��� �������')
INSERT Practise_progress VALUES(19, 15, N'�����'); INSERT Exam_progress VALUES(19, 9, N'����')
INSERT Practise_progress VALUES(20, 15, N'�����'); INSERT Exam_progress VALUES(20, 9, N'�� ����')
INSERT Practise_progress VALUES(21, 15, N'�����'); INSERT Exam_progress VALUES(21, 9, N'����')
INSERT Practise_progress VALUES(22, 15, N'�����'); INSERT Exam_progress VALUES(21, 9, N'����')
INSERT Practise_progress VALUES(23, 15, N'�����'); INSERT Exam_progress VALUES(23, 9, N'����')
INSERT Practise_progress VALUES(24, 15, N'�������'); INSERT Exam_progress VALUES(24, 9, N'��� �������')
INSERT Practise_progress VALUES(25, 15, N'�����'); INSERT Exam_progress VALUES(25, 9, N'����')
INSERT Practise_progress VALUES(26, 15, N'�����'); INSERT Exam_progress VALUES(26, 9, N'����')
INSERT Practise_progress VALUES(27, 15, N'�����'); INSERT Exam_progress VALUES(27, 9, N'����')
INSERT Practise_progress VALUES(28, 15, N'�������'); INSERT Exam_progress VALUES(28, 9, N'��� �������')
INSERT Practise_progress VALUES(29, 15, N'�������'); INSERT Exam_progress VALUES(29, 9, N'��� �������')
INSERT Practise_progress VALUES(30, 15, N'�������'); INSERT Exam_progress VALUES(30, 9, N'��� �������')
INSERT Practise_progress VALUES(31, 15, N'�����'); INSERT Exam_progress VALUES(31, 9, N'����')


INSERT Practise_progress VALUES(32, 16, N'�����'); INSERT Exam_progress VALUES(32, 10, N'����')
INSERT Practise_progress VALUES(33, 16, N'�����'); INSERT Exam_progress VALUES(33, 10, N'����')
INSERT Practise_progress VALUES(34, 16, N'�������'); INSERT Exam_progress VALUES(34, 10, N'��� �������')
INSERT Practise_progress VALUES(35, 16, N'�����'); INSERT Exam_progress VALUES(35, 10, N'����')
INSERT Practise_progress VALUES(36, 16, N'�����'); INSERT Exam_progress VALUES(36, 10, N'�� ����')
INSERT Practise_progress VALUES(37, 16, N'�������'); INSERT Exam_progress VALUES(37, 10, N'��� �������')

INSERT Practise_progress VALUES(32, 8, N'�����');
INSERT Practise_progress VALUES(33, 8, N'�����');
INSERT Practise_progress VALUES(34, 8, N'�������');
INSERT Practise_progress VALUES(35, 8, N'�����'); 
INSERT Practise_progress VALUES(36, 8, N'�������'); 
INSERT Practise_progress VALUES(37, 8, N'�����'); 


INSERT Practise_progress VALUES(38, 17, N'�����'); INSERT Exam_progress VALUES(38, 11, N'����')
INSERT Practise_progress VALUES(39, 17, N'�������'); INSERT Exam_progress VALUES(39, 11, N'����')


INSERT Practise_progress VALUES(38, 23, N'�����'); INSERT Exam_progress VALUES(38, 17, N'����')
INSERT Practise_progress VALUES(39, 23, N'�������'); INSERT Exam_progress VALUES(39, 17, N'����')

INSERT Practise_progress VALUES(38, 15, N'�����'); INSERT Exam_progress VALUES(38, 9, N'����')
INSERT Practise_progress VALUES(39, 15, N'�������'); INSERT Exam_progress VALUES(39, 9, N'����')
 -- ����� ���������� �������������� �������
-- ����� ������� ������ "����� ���� ���������, ������� ��� ������������ �������� � ���� �� ����� ��������� �������"
