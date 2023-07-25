PRAGMA foreign_keys=ON;
BEGIN TRANSACTION;
CREATE TABLE Student
(nr varchar2(5) not null,
 name varchar2(50) not null,
 CONSTRAINT student_pk PRIMARY KEY (nr)
);
INSERT INTO Student VALUES('100','João');
INSERT INTO Student VALUES('110','Manuel');
INSERT INTO Student VALUES('120','Rui');
INSERT INTO Student VALUES('130','Abel');
INSERT INTO Student VALUES('140','Fernando');
INSERT INTO Student VALUES('150','Ismael');
CREATE TABLE prof
(acronym varchar2(5)not null,
 name    varchar2(50)not null,
 CONSTRAINT prof_pk PRIMARY KEY (acronym)
);
INSERT INTO prof VALUES('ECO','Eugénio');
INSERT INTO prof VALUES('FNF','Fernando');
INSERT INTO prof VALUES('JLS','João');
CREATE TABLE course
(code varchar2(5) not null,
 name varchar2(50) not null,
    department varchar2(10) not null,
    director varchar2(5) REFERENCES prof(acronym),
 CONSTRAINT course_pk PRIMARY KEY (code)
);
INSERT INTO course VALUES('TS1','Teoria dos Sistemas 1','IS','FNF');
INSERT INTO course VALUES('BD','Bases de Dados','IS','ECO');
INSERT INTO course VALUES('EIA','Estruturas de Informação e Algoritmos','IS','ECO');
INSERT INTO course VALUES('EP','Electrónica de Potência','AC','JLS');
INSERT INTO course VALUES('IE','Anstalações Eléctricas','AC','JLS');
CREATE TABLE exam
(student_nr varchar2(5) REFERENCES Student(nr),
 course_code varchar2(50) REFERENCES course(code),
    exam_date date,
    grade number(2) check (grade>=0 AND grade<=20),
 CONSTRAINT exam_pk PRIMARY KEY (student_nr, course_code, exam_date)
);
INSERT INTO exam VALUES('100','TS1','92-02-11',8);
INSERT INTO exam VALUES('100','TS1','93-02-02',11);
INSERT INTO exam VALUES('100','BD','93-02-04',17);
INSERT INTO exam VALUES('100','EIA','92-01-29',16);
INSERT INTO exam VALUES('100','EIA','93-02-02',13);
INSERT INTO exam VALUES('110','EP','92-01-30',12);
INSERT INTO exam VALUES('110','IE','92-02-05',10);
INSERT INTO exam VALUES('110','IE','93-02-01',14);
INSERT INTO exam VALUES('120','TS1','93-01-31',15);
INSERT INTO exam VALUES('120','EP','93-02-04',13);
INSERT INTO exam VALUES('130','BD','93-02-04',12);
INSERT INTO exam VALUES('130','EIA','93-02-02',7);
INSERT INTO exam VALUES('130','TS1','92-02-11',8);
INSERT INTO exam VALUES('140','TS1','93-01-31',10);
INSERT INTO exam VALUES('140','TS1','92-02-11',13);
INSERT INTO exam VALUES('140','EIA','93-02-02',11);
INSERT INTO exam VALUES('150','TS1','92-02-11',10);
INSERT INTO exam VALUES('150','EP','93-02-02',11);
INSERT INTO exam VALUES('150','BD','93-02-04',17);
INSERT INTO exam VALUES('150','EIA','92-01-29',16);
INSERT INTO exam VALUES('150','IE','93-02-02',13);
COMMIT;
