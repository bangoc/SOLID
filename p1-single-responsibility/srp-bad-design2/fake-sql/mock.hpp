#ifndef FAKE_SQL_MOCK_HPP_
#define FAKE_SQL_MOCK_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <string>
#include <vector>

class SqlTransaction {
public:
  void Commit() {
  }
};

enum SqlCommandType {
  StoredProcedure
};

class Parameters {
public:
  template<typename T>
  void AddWithValue(std::string name, T value) {
  }
};

struct SqlCommand {
  void ExecuteNonQuery() {
  }

  SqlTransaction *transaction;
  SqlCommandType command_type;
  std::string command_text;
  Parameters params;
};

class SqlConnection {
public:
  SqlConnection(std::string conn_str) {
  };
  void Open() {
  }
  SqlCommand *CreateCommand() {
    SqlCommand *cmd = new SqlCommand();
    commands.push_back(cmd);
    return cmd;
  }
  SqlTransaction *BeginTransaction() {
    SqlTransaction *trans = new SqlTransaction();
    transactions.push_back(trans);
    return trans;
  }
  void Close() {
    for (auto t: transactions) {
      delete t;
    }
    for (auto c: commands) {
      delete c;
    }
  }
private:
  std::vector<SqlTransaction*> transactions;
  std::vector<SqlCommand*> commands;
};

#endif  // FAKE_SQL_MOCK_HPP_