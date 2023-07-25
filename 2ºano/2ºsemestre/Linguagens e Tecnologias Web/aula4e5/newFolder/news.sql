CREATE TABLE users (
  username VARCHAR PRIMARY KEY,      -- unique username
  password VARCHAR,                  -- password stored in sha-1
  name VARCHAR                       -- real name
);

CREATE TABLE news (
  id INTEGER PRIMARY KEY,            -- article id
  title VARCHAR,                     -- title of the article
  published INTEGER,                 -- date when the article was published in epoch format
  tags VARCHAR,                      -- comma separated tags
  username VARCHAR REFERENCES users, -- user that wrote the article
  introduction VARCHAR,              -- a introductory paragraph
  fulltext VARCHAR                   -- the rest of the text
);

CREATE TABLE comments (
  id INTEGER PRIMARY KEY,            -- comment id
  news_id INTEGER REFERENCES news,   -- news item this comment is about
  username VARCHAR REFERENCES users, -- user that wrote the comment
  published INTEGER,                 -- date when news item was published in epoch format
  text VARCHAR                       -- comment text
);

-- All passwords are 1234 in SHA-1 format
INSERT INTO users VALUES ("dominic", "7110eda4d09e062aa5e4a390b0a572ac0d2c0220", "Dominic Woods");
INSERT INTO users VALUES ("zachary", "7110eda4d09e062aa5e4a390b0a572ac0d2c0220", "Zachary Young");
INSERT INTO users VALUES ("alicia",  "7110eda4d09e062aa5e4a390b0a572ac0d2c0220", "Alicia Hamilton");
INSERT INTO users VALUES ("abril",   "7110eda4d09e062aa5e4a390b0a572ac0d2c0220", "Abril Cooley");

INSERT INTO news VALUES (NULL,
  'Lorem ipsum dolor sit amet, consectetur',
  1507901651,
  'politics,economy',
  'abril',
  'Nulla facilisi. Proin et lectus dapibus, fermentum nisi a, varius nulla. Sed massa dolor, commodo at iaculis id, facilisis ut erat. Ut ac fringilla sem. Ut vel eros suscipit, convallis arcu porttitor, fringilla purus. Pellentesque eget sapien sem. Maecenas eget pharetra ipsum. Ut sollicitudin sem non feugiat pharetra.',
  'Aliquam justo nibh, lacinia suscipit odio nec, condimentum tincidunt urna. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec lacus mi, blandit nec dolor in, ultrices condimentum elit. Quisque interdum, ante non pellentesque viverra, ipsum velit ultrices tortor, id rhoncus orci est at augue. In hac habitasse platea dictumst. Donec dolor nisi.

Suspendisse potenti. Nullam lacinia dictum massa sed sagittis. Sed id ultrices libero. Cras convallis commodo ante, quis sagittis erat vulputate et. Cras nunc lorem, mollis a nibh eget, dignissim auctor lorem. Suspendisse placerat convallis ante vitae dapibus. Donec tellus felis, tincidunt eget iaculis eget, varius non turpis. Curabitur in eros at sapien fringilla venenatis eu a risus. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Pellentesque eu consectetur tellus. Suspendisse vitae urna ex. Cras sit amet enim id turpis gravida lacinia a vitae lacus. Vivamus augue ante, pellentesque sed semper non, rutrum ornare ante. Orci varius.');

INSERT INTO news VALUES (NULL,
  'Donec placerat tempor ex sit amet',
  1508074451,
  'local,life',
  'alicia',
  'Nam aliquet leo vel scelerisque sagittis. Praesent hendrerit lectus et augue condimentum, vitae dapibus elit bibendum. Quisque id sapien nec nisl commodo vulputate. Cras vehicula semper lectus. Duis a purus in velit iaculis luctus id ac justo. Mauris a lectus eu dui aliquam pretium nec a massa. Suspendisse risus metus, laoreet quis velit eu, mollis auctor tellus. Maecenas vulputate, nulla a commodo porttitor, urna arcu viverra dolor, a eleifend lectus leo a justo.',
  'Morbi bibendum volutpat pellentesque. In bibendum est et orci semper rhoncus. Sed cursus vel orci sed malesuada. Fusce ac dictum ligula, quis hendrerit ipsum. Proin hendrerit a.

Nulla commodo eu nulla ac facilisis. Donec ante lorem, tincidunt nec interdum vulputate, fringilla a urna. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla sapien erat, suscipit a nisl sed, molestie convallis eros. Curabitur egestas massa et metus dignissim, et vestibulum libero porttitor. Sed non metus pharetra, lobortis orci a, commodo diam. Praesent a sagittis massa, quis condimentum augue. Donec id est feugiat ipsum egestas vulputate vel in dolor. Pellentesque pretium placerat lorem, sed sodales diam molestie a. Donec dictum dui ut accumsan tempor. Nam vestibulum in erat et sagittis. Donec venenatis, ante vitae tristique tristique, nisi metus aliquet.');

INSERT INTO news VALUES (NULL,
  'Vivamus fermentum dui nisi, at posuere',
  1508160851,
  'nature,science',
  'zachary',
  'Donec magna sapien, feugiat vel commodo et, aliquam in purus. Duis posuere, orci eu mollis lobortis, eros augue aliquam augue, et posuere metus nisl semper quam. In tortor nulla, iaculis at varius a, pharetra et lectus. Pellentesque convallis nibh id justo pellentesque, at sollicitudin ex auctor. Nulla ornare rutrum est, ac faucibus turpis interdum et. Vivamus nisi metus, tempor in dapibus in, vestibulum eget diam. Nunc tristique ante eu diam porta, id consectetur ligula sagittis. Pellentesque eu leo vel felis eleifend luctus eget sit amet ligula. Ut semper ante tristique interdum imperdiet. Mauris et libero varius, sollicitudin turpis at, ullamcorper.',
  'Nullam et arcu non tellus congue ultrices id id enim. Donec malesuada, neque ut euismod ullamcorper, massa dui congue ante, quis scelerisque enim arcu vel turpis. Praesent ornare elementum finibus. Integer aliquam risus ac lorem mollis, sit amet dignissim dolor faucibus. Praesent non eros ut ligula rhoncus egestas. Duis ex nibh, maximus eget vulputate nec, sagittis in ex. Suspendisse potenti.

Praesent pellentesque, nisi ut ultrices sagittis, mauris urna tincidunt nibh, eu faucibus ante nisi eu nisl. Quisque commodo est non sapien rhoncus, a fringilla tellus ultricies. Curabitur eget massa mauris. Sed semper ultrices ante, in cursus enim vehicula at. Praesent.');

INSERT INTO news VALUES (NULL,
  'Quisque a dapibus magna, non scelerisque',
  1508247278,
  'transports,vehicles',
  'dominic',
  'Etiam massa magna, condimentum eu facilisis sit amet, dictum ac purus. Curabitur semper nisl vel libero pulvinar ultricies. Proin dignissim dolor nec scelerisque bibendum. Maecenas a sem euismod, iaculis erat id, convallis arcu. Ut mollis, justo vitae suscipit imperdiet, eros dui laoreet enim, fermentum posuere felis arcu vel urna. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Proin blandit ex sit amet suscipit commodo. Duis molestie ligula eu urna tincidunt tincidunt. Mauris posuere aliquet pellentesque. Fusce molestie libero arcu, ut porta massa iaculis sit amet. Fusce varius nisl vitae fermentum fringilla. Pellentesque a cursus lectus.',
  'Duis condimentum metus et ex tincidunt, faucibus aliquet ligula porttitor. In vitae posuere massa. Donec fermentum magna sit amet suscipit pulvinar. Cras in elit sapien. Vivamus nunc sem, finibus ac suscipit ullamcorper, hendrerit vitae urna. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Quisque eget tincidunt orci. Mauris congue ipsum non purus tristique, at venenatis elit pellentesque. Etiam congue euismod molestie. Mauris ex orci, lobortis a faucibus sed, sagittis eget neque.

Mauris tincidunt orci congue turpis viverra pulvinar. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Quisque rhoncus lorem eget.');

INSERT INTO comments VALUES (NULL,
  4,
  'dominic',
  1508247532,
  'Aliquam maximus commodo dui, ut viverra urna vulputate et. Donec posuere vitae sem sed vehicula. Sed in erat eu diam fringilla sodales. Aenean lacinia vulputate nisl, dignissim dignissim nisl. Nam at nibh mollis, facilisis nibh sit amet, mattis urna. Maecenas.'
);

INSERT INTO comments VALUES (NULL,
  4,
  'abril',
  1508247632,
  'Duis scelerisque purus fermentum turpis euismod congue. Phasellus sit amet sem mollis, imperdiet quam porta, volutpat purus. In et sodales urna, sed cursus lectus. Vivamus a massa vitae nisl lobortis laoreet nec tristique magna. Mauris egestas ipsum eu sem lacinia.'
);

INSERT INTO comments VALUES (NULL,
  3,
  'alicia',
  1508247132,
  'Phasellus at neque nec nunc scelerisque eleifend eu eu risus. Praesent in nibh viverra, posuere ligula condimentum, accumsan tellus. Vivamus varius sem a mauris finibus, ac iaculis risus scelerisque. Nullam fermentum leo dui, at fermentum tellus consequat id. Pellentesque eleifend.'
);
