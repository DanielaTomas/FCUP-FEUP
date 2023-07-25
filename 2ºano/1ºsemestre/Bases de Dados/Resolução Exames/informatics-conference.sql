PRAGMA foreign_keys=ON;
.mode columns
.headers on
.nullvalue NULL

DROP TABLE IF EXISTS Talk;
DROP TABLE IF EXISTS Speaker;
DROP TABLE IF EXISTS Topic;

CREATE TABLE Speaker (
	Id INTEGER PRIMARY KEY,
	Name Text Not Null,
	Institution Text Not Null,
	Country Text Not Null);

CREATE TABLE Topic (
	Id INTEGER PRIMARY KEY,
	Name Text NOT NULL);

CREATE TABLE Talk (
	speaker INTEGER REFERENCES Speaker,
	topic INTEGER REFERENCES Topic,
	Title Text NOT NULL,
	Day Text,
	PRIMARY KEY (speaker, topic, Title));


INSERT INTO Speaker VALUES (1, "Jeffrey Ullman", "Stanford University", "USA");
INSERT INTO Speaker VALUES (2, "Gabriel David", "University of Porto", "Portugal");
INSERT INTO Speaker VALUES (3, "Bill Gates", "Gates Foundation", "USA");
INSERT INTO Speaker VALUES (4, "Yoshua Bengio", "Université de Montréal", "Canada");
INSERT INTO Speaker VALUES (5, "Grady Booch", "IBM Research", "USA");
INSERT INTO Speaker VALUES (6, "Ademar Aguiar", "University of Porto", "Portugal");
INSERT INTO Speaker VALUES (7, "Arlindo Oliveira", "IST", "Portugal");
INSERT INTO Speaker VALUES (8, "Carles Sierra", "IIIA", "Spain");

INSERT INTO Topic VALUES (1, "Intelligent Systems");
INSERT INTO Topic VALUES (2, "Databases");
INSERT INTO Topic VALUES (3, "Software Engineering");
INSERT INTO Topic VALUES (4, "Computer Graphics");
INSERT INTO Topic VALUES (5, "Programming Languages");
INSERT INTO Topic VALUES (6, "Social Impact");

INSERT INTO Talk VALUES (1, 2, "To sequel or not to sequel", "Monday");
INSERT INTO Talk VALUES (2, 2, "The future of database systems", NULL);
INSERT INTO Talk VALUES (3, 3, "Software Engineering at Microsoft", "Monday");
INSERT INTO Talk VALUES (4, 1, "Deep Learning Applications", "Wednesday");
INSERT INTO Talk VALUES (5, 3, "How to thrive in SE", "Monday");
INSERT INTO Talk VALUES (6, 3, "Agile Software Engineering", "Tuesday");
INSERT INTO Talk VALUES (7, 1, "Building Synthetic Brains", NULL);
INSERT INTO Talk VALUES (8, 1, "Intelligent Agent Applications", "Monday");
INSERT INTO Talk VALUES (3, 6, "Social Responsibility of Success", "Monday");
INSERT INTO Talk VALUES (5, 1, "Artificial Intelligence is your friend", NULL);