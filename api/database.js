const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'peppiuser',
  password: 'peppipass',
  database: 'peppi'
});
module.exports = connection;