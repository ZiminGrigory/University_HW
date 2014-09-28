/*2.      Написать функцию для перевода студента из группы в группу. Функция должна вернуть таблицу из экзаменов
, которые необходимо сдать студенту, чтобы ликвидировать разницу в программе. 
Входные параметры: номер зачетной книжки студента, старый и новый номера группы.
 Студент может быть переведен из группы в группу, если разница в программе 
 (количество обязательных семинаров и экзаменов для новой группы по сравнению с количеством обязательных семинаров и экзаменов в старой)
  составляет не более 10% от общего количества семинаров и экзаменов новой группы. 
  Если разница превышает этот порог, должно быть возвращено исключение. */


CREATE FUNCTION f2 (
	@st_id INT,
	@fst_gr SMALLINT,
	@snd_gr SMALLINT
)
RETURNS @table TABLE (ЭКЗАМЕНЫ NVARCHAR(40), ЗАЧЕТЫ NVARCHAR(40))
BEGIN
	DECLARE @oldGroup TABLE (ЭКЗАМЕНЫ NVARCHAR(40), ЗАЧЕТЫ NVARCHAR(40));
	DECLARE @newGroup TABLE (ЭКЗАМЕНЫ NVARCHAR(40), ЗАЧЕТЫ NVARCHAR(40));
	
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
		= (SELECT COUNT(ЗАЧЕТЫ) FROM @newGroup WHERE ЗАЧЕТЫ IS NOT NULL)
			+ (SELECT COUNT(ЭКЗАМЕНЫ) FROM @newGroup WHERE ЭКЗАМЕНЫ IS NOT NULL)
	
	DECLARE @difference INT =
		(SELECT COUNT(a.ЗАЧЕТЫ) FROM 
			(SELECT ЗАЧЕТЫ FROM @newGroup WHERE ЗАЧЕТЫ IS NOT NULL EXCEPT SELECT ЗАЧЕТЫ FROM @oldGroup WHERE ЗАЧЕТЫ IS NOT NULL) a)
		+ (SELECT COUNT(b.ЭКЗАМЕНЫ) FROM 
			(SELECT ЭКЗАМЕНЫ FROM @newGroup WHERE ЗАЧЕТЫ IS NOT NULL EXCEPT SELECT ЭКЗАМЕНЫ FROM @oldGroup WHERE ЗАЧЕТЫ IS NOT NULL) b)

	IF CAST(CAST ( @difference AS FLOAT) / CAST(@common_count_in_new AS FLOAT) AS FLOAT) > 0.1 
		--это не совсем исключение, но в функциях иначе никак
		DECLARE @fakeERROR INT = CAST(N'Разница превышает 10%, перевод невозможен' as int) 
	
	INSERT INTO @table SELECT * 
		FROM (SELECT ЭКЗАМЕНЫ FROM @newGroup WHERE ЗАЧЕТЫ IS NOT NULL EXCEPT SELECT ЭКЗАМЕНЫ FROM @oldGroup WHERE ЗАЧЕТЫ IS NOT NULL) a
		 FULL OUTER JOIN
		 (SELECT ЗАЧЕТЫ FROM @newGroup WHERE ЗАЧЕТЫ IS NOT NULL EXCEPT SELECT ЗАЧЕТЫ FROM @oldGroup WHERE ЗАЧЕТЫ IS NOT NULL) b
				ON a.ЭКЗАМЕНЫ = b.ЗАЧЕТЫ WHERE (ЗАЧЕТЫ IS NOT NULL AND ЭКЗАМЕНЫ IS NOT NULL) OR (ЗАЧЕТЫ IS NOT NULL) OR (ЭКЗАМЕНЫ IS NOT NULL)
	RETURN
END

SELECT * FROM f2(12, 123, 245)

--заполнение студента и группы, чтобы прошла функция 
INSERT Students VALUES (N'Семёнова Василиса Николаевна', 145)

INSERT Group_duty VALUES (145, 1, 1)
INSERT Group_duty VALUES (145, 18, 24)
INSERT Group_duty VALUES (145, 3, 9)
INSERT Group_duty VALUES (145, 7, 13)
INSERT Group_duty VALUES (145, 2, NULL)
INSERT Group_duty VALUES (145, NULL, 8)

SELECT * FROM f2(12, 123, 145)

/*3. Написать процедуру для перевода всех студентов, успешно сдавших все обязательные экзамены на следующий курс. 
Входные параметры: текущий номер группы, номер группы на следующем курсе. Выходной параметр: количество переведенных студентов.*/

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