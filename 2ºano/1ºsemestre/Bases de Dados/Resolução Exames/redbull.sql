Pragma Foreign_Keys = on;
.mode columns
.headers on
drop table if exists Team;
create table Team (
  name text PRIMARY KEY,
  country text
);

drop table if exists Aircraft;
create table Aircraft (
  model text,
  horsepower int,
  topspeed int,
  width int,
  height int,
  weight int
);

drop table if exists Pilot;
create table Pilot (
  num int PRIMARY KEY,
  firstname text,
  surname text,
  nationality text,
  birthday date,
  team text references Team,
  aircraft text references Aircraft
);

drop table if exists Race;
create table Race (
  location text,
  edition int,
  country text,
  data date,
  gates text,
  eliminations text
);

drop table if exists Participation;
create table Participation (
  pilot references	Pilot,
  [location text,	edition	int] references	Race,
  trainingtime time,
  trainingpos text,
  trainingpenalty text,
  qualificationtime time,
  qualificationpos text,
  qualificationpenalty text,
  eliminationtime time,
  eliminationpos text,
  eliminationpenalty text
);

drop table if exists Duel;
create table Duel (
  pilot1 text references	Pilot,
  pilot2 text references	Pilot,	
  [location,	edition]	references	Race,
  dueltype text,
  timepilot1 time,
  timepilot2 time,
  penaltypilot1 text,
  penaltypilot2 text
);
