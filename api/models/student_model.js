const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const student = {
  getById: function(id, callback) {
    return db.query('select * from student where id_student=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from student', callback);
  },
  add: function(student, callback) {
    bcrypt.hash(student.password, saltRounds, function(err, hash) {
      return db.query('insert into student (fname,lname,username, password) values(?,?,?,?)',
      [student.fname, student.lname, student.username, hash], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from student where id_student=?', [id], callback);
  },
  update: function(id,student, callback) {
    bcrypt.hash(student.password, saltRounds, function(err, hash) {
      return db.query('update student set fname=?,lname=?,username=?, password=? WHERE id_student=?',
      [student.fname, student.lname, student.username, hash, id], callback);
    });
  },
  getGrades:function(username,callback){
    return db.query('SELECT fname, lname, name, grade FROM student INNER JOIN grade ON student.id_student=grade.id_student INNER JOIN course ON course.id_course=grade.id_course where username =?', 
    [username], callback);
  }
};
module.exports = student;