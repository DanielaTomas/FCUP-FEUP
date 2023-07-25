PRAGMA foreign_keys = On;

drop table if exists Request;
drop table if exists AuthorsList; 
drop table if exists LiteraryWork;
drop table if exists Author;
drop table if exists Student;

create table Student (
	code int primary key,
	fullName varchar(100) not null
);

create table Author (
	authorId varchar(10) primary key,
	firstName varchar(50) not null,
	lastName varchar(50) not null,
	nationality varchar(10) not null
);

create table LiteraryWork (
	code varchar(20) primary key,
	name varchar(50) not null,
	publicationYear int not null,
	publicationCity varchar(50) not null,
	publisher varchar(50) not null,
	floor varchar(10) not null,
	bookcase varchar(10) not null,
	shelf varchar(10) not null,
	type varchar(20) not null,
	domain varchar(20) not null
);

create table AuthorsList (
	literaryWorkCode varchar(20) not null,
	authorId varchar(10) not null,
	PRIMARY KEY (literaryWorkCode, authorId),
	FOREIGN KEY (literaryWorkCode) REFERENCES LiteraryWork (code),
	FOREIGN KEY (authorId) REFERENCES Author (authorId)	
);

create table Request (
	literaryWorkCode varchar(20) not null,
	studentCode int not null,
	dateTimeRequest datetime not null,
	dateTimeReturn datetime,
	FOREIGN KEY (literaryWorkCode) REFERENCES LiteraryWork (code),
	FOREIGN KEY (studentCode) REFERENCES Student (code),
	PRIMARY KEY (literaryWorkCode, studentCode)
);




INSERT INTO Student VALUES (1, 'Liam');
INSERT INTO Student VALUES (2, 'Olivia');
INSERT INTO Student VALUES (3, 'Emma');
INSERT INTO Student VALUES (4, 'Noah');
INSERT INTO Student VALUES (5, 'Oliver');

INSERT INTO Author VALUES ('AS443', 'Abraham', 'Stackhouse', 'NO');
INSERT INTO Author VALUES ('AW980', 'Amelia', 'Wangerin, Jr.', 'NZ');
INSERT INTO Author VALUES ('AI923', 'Anastasia', 'Inez', 'NZ');
INSERT INTO Author VALUES ('AM329', 'Arthur', 'McCrumb', 'NZ');
INSERT INTO Author VALUES ('AH957', 'Arturo', 'Hijuelos', 'ES');

INSERT INTO LiteraryWork VALUES ('BB194', 'Ballinby Boys', 1942, 'London', 'Cedar House Publishers', 1, 1, 'A', 'Article', 'History');
INSERT INTO LiteraryWork VALUES ('NC652', 'Nothing But Capers', 2012, 'Berlin', 'Sound & Seas Co.', 1, 2, 'B', 'Magazine', 'History');
INSERT INTO LiteraryWork VALUES ('AD222', 'Alanna Saves the Day', 1968, 'Madrid', 'Palimpsest Printing', 1, 3, 'C', 'Article', 'Languages');
INSERT INTO LiteraryWork VALUES ('PA169', 'Post Alley', 1953, 'Rome', 'Etaoin Shrdlu Press', 1, 4, 'D', 'Article', 'Languages');
INSERT INTO LiteraryWork VALUES ('TC188', 'Thatchwork Cottage', 1967, 'Paris', 'Cedar House Publishers', 1, 5, 'E', 'Magazine', 'Science');
INSERT INTO LiteraryWork VALUES ('ZT703', 'Zero over Twelve', 1960, 'Hamburg', 'Sound & Seas Co.', 1, 6, 'F', 'Article', 'Languages');
INSERT INTO LiteraryWork VALUES ('PP866', 'Portmeirion', 1956, 'Budapest', 'Palimpsest Printing', 1, 7, 'G', 'Book', 'Science');
INSERT INTO LiteraryWork VALUES ('RR774', 'Rystwyth', 2006, 'Vienna', 'Etaoin Shrdlu Press', 1, 8, 'H', 'Magazine', 'History');
INSERT INTO LiteraryWork VALUES ('TM925', 'The Mallemaroking', 1943, 'Warsaw', 'Cedar House Publishers', 1, 9, 'I', 'Magazine', 'History');
INSERT INTO LiteraryWork VALUES ('CH391', 'Can I Be Honest?', 1985, 'Bucharest', 'Sound & Seas Co.', 1, 1, 'J', 'Magazine', 'History');
INSERT INTO LiteraryWork VALUES ('NL209', 'No More Lightning', 2015, 'Stockholm', 'Sound & Seas Co.', 1, 1, 'K', 'Magazine', 'Languages');
INSERT INTO LiteraryWork VALUES ('NR695', '9803 North Millworks Road', 1961, 'Munich', 'Palimpsest Printing', 2, 3, 'L', 'Magazine', 'Languages');

INSERT INTO AuthorsList VALUES ('BB194', 'AS443');
INSERT INTO AuthorsList VALUES ('NC652', 'AW980');
INSERT INTO AuthorsList VALUES ('AD222', 'AI923');
INSERT INTO AuthorsList VALUES ('PA169', 'AM329');
INSERT INTO AuthorsList VALUES ('TC188', 'AH957');
INSERT INTO AuthorsList VALUES ('ZT703', 'AS443');
INSERT INTO AuthorsList VALUES ('PP866', 'AW980');
INSERT INTO AuthorsList VALUES ('RR774', 'AI923');
INSERT INTO AuthorsList VALUES ('TM925', 'AM329');
INSERT INTO AuthorsList VALUES ('CH391', 'AH957');
INSERT INTO AuthorsList VALUES ('NL209', 'AS443');
INSERT INTO AuthorsList VALUES ('NL209', 'AW980');
INSERT INTO AuthorsList VALUES ('NR695', 'AI923');

INSERT INTO Request VALUES ('BB194', 5, '2018-04-13 11:10:21', '2018-04-19 12:45:08');
INSERT INTO Request VALUES ('BB194', 2, '2018-07-19 12:47:36', '2018-08-12 16:06:10');
INSERT INTO Request VALUES ('NC652', 1, '2018-03-30 10:47:51', '2018-04-15 14:33:17');
INSERT INTO Request VALUES ('AD222', 1, '2020-02-09 15:21:53', '2020-02-18 10:22:04');
INSERT INTO Request VALUES ('PA169', 4, '2018-01-10 10:45:40', '2018-02-08 16:34:34');
INSERT INTO Request VALUES ('ZT703', 2, '2020-12-08 13:09:27', '2020-12-15 17:50:03');
INSERT INTO Request VALUES ('ZT703', 1, '2020-12-01 15:03:57', '2020-12-22 15:20:04');
INSERT INTO Request VALUES ('TC188', 2, '2020-03-18 12:02:17', '2020-03-27 17:18:51');
INSERT INTO Request VALUES ('NR695', 3, '2019-02-05 13:25:01', '2019-02-06 16:07:44');
INSERT INTO Request VALUES ('NL209', 5, '2020-01-13 15:57:48', '2020-01-23 09:49:06');
INSERT INTO Request VALUES ('RR774', 2, '2018-05-23 14:05:25', '2018-06-13 17:21:14');
INSERT INTO Request VALUES ('CH391', 2, '2020-09-15 15:45:56', '2020-10-12 09:34:11');
INSERT INTO Request VALUES ('CH391', 3, '2021-04-26 11:12:52', '2021-05-12 15:46:57');
INSERT INTO Request VALUES ('PP866', 1, '2020-04-01 15:07:59', '2020-04-16 10:49:29');
INSERT INTO Request VALUES ('PP866', 4, '2019-07-31 09:12:54', '2019-08-07 14:58:33');
INSERT INTO Request VALUES ('BB194', 1, '2019-01-10 13:33:09', '2019-01-22 16:29:21');
INSERT INTO Request VALUES ('NL209', 1, '2020-10-04 09:26:52', '2020-11-01 12:48:53');
INSERT INTO Request VALUES ('ZT703', 4, '2019-09-09 12:06:38', '2019-09-14 16:02:42');

INSERT INTO Request (literaryWorkCode, studentCode, dateTimeRequest) VALUES ('PP866', 2, '2022-01-09 12:03:29');
INSERT INTO Request (literaryWorkCode, studentCode, dateTimeRequest) VALUES ('RR774', 3, '2022-01-22 15:08:24');
INSERT INTO Request (literaryWorkCode, studentCode, dateTimeRequest) VALUES ('CH391', 5, '2022-01-21 12:56:25');