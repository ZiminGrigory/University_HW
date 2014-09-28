/*Создать триггер на удаление студента. 
При удалении студента проверять
, остались ли еще студенты в его группе. Если студентов больше не осталось, удалить группу.*/

CREATE TRIGGER T2 ON Students
FOR DELETE AS
BEGIN
	DECLARE @gr_number INT = (SELECT gr_number FROM deleted) 
	IF (SELECT COUNT(*) FROM Students WHERE gr_number = @gr_number) = 0
		DELETE FROM Group_duty WHERE gr_number = @gr_number
END

INSERT Students VALUES (N'Приговоренный к удалению',404)
INSERT Group_duty VALUES (404, 1, 1)
INSERT Group_duty VALUES (404, 2, 3)
DELETE FROM Students WHERE full_name = N'Приговоренный к удалению'

SELECT a.gr_number, full_name FROM Group_duty a JOIN Students b ON a.gr_number = b.gr_number WHERE  a.gr_number = 404

/*Создать триггер на удаление зависимости экзамена от семинара. 
	При удалении зависимости, необходимо проверять
	, что количество всех обязательных семинаров для экзамена не станет меньше,
	 чем минимальное допустимое количество необходимых семинаров для экзамена,
	  и удалять только в том случае, если остается достаточное количество семинаров. */

CREATE TRIGGER T1 ON Exams_requirements
FOR DELETE AS
BEGIN
	DECLARE @ex_id INT = (SELECT exam_id FROM deleted) 
	DECLARE @pr_id INT = (SELECT practise_for_exam FROM deleted) 
	IF (SELECT university_subject FROM Exams WHERE id = @ex_id) = (SELECT university_subject FROM Practise_exams WHERE id = @pr_id)
		ROLLBACK
END

/*from feed
--добавление зависимостей для работы тригера в дальнейшем
INSERT Exams_requirements VALUES (15,16) --добавили для химии обязательный зачет -философию
INSERT Exams_requirements VALUES (15,22)*/

DELETE FROM Exams_requirements WHERE exam_id = 1 AND practise_for_exam = 1
DELETE FROM Exams_requirements WHERE exam_id = 15 AND practise_for_exam = 16
