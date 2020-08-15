#include <iostream>

namespace not_so_good {

    namespace db {

        struct DbConnection {
            // a lot of code here

            bool connect() {
                return true;
            }
        };

    }

    // GUI module
    namespace gui {

        struct MainForm {
            // a lot of code here....

            void doSomething() {
                m_connection.connect();
                /// 
            }
        private:
            db::DbConnection m_connection;
        };

    }

}



namespace better {

    namespace db {

        struct IDBConnection {
            virtual ~IDBConnection();

            virtual bool connect() = 0;
        };

        struct DBConnection : public IDBConnection {
            // a lot of code here

            bool connect() {
                return true;
            }
        };

    }

    // GUI module
    namespace gui {

        struct MainForm {
            MainForm(std::unique_ptr<db::IDBConnection> connection) {

            }
            // a lot of code here....

            void doSomething() {
                m_connection->connect();
                /// 
            }
        private:
            std::unique_ptr<db::IDBConnection> m_connection;
        };
    }
}




namespace nice {

    // GUI module
    namespace gui {

        struct IDBConnection {
            virtual ~IDBConnection();

            virtual bool connect() = 0;
        };

        struct MainForm {
            MainForm(std::unique_ptr<gui::IDBConnection> connection) {

            }
            // a lot of code here....

            void doSomething() {
                m_connection->connect();
                /// 
            }
        private:
            std::unique_ptr<gui::IDBConnection> m_connection;
        };
    }

    namespace db {

        struct DBConnection : public gui::IDBConnection {
            // a lot of code here

            bool connect() {
                return true;
            }
        };

    }
}


int main() {

    return 0;
}