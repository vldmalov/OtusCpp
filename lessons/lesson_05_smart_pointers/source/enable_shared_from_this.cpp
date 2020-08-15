#include <iostream>
#include <memory>
#include <vector>

namespace basic {

    struct SomeStruct : std::enable_shared_from_this<SomeStruct> {
        SomeStruct() {
            std::cout << "ctor" << std::endl;
        }
        ~SomeStruct() {
            std::cout << "dtor" << std::endl;
        }

        std::shared_ptr<SomeStruct> getPtr() {
            return shared_from_this();
        }
    };

    void example() {
        std::cout << "basic::example" << std::endl;
        {
            auto ptr1 = std::shared_ptr<SomeStruct>{new SomeStruct{}};
            auto ptr2 = ptr1->getPtr();
            std::cout << "before scope end" << std::endl;
        }
        std::cout << "after scope" << std::endl;
        std::cout << std::endl;
    }
} // namespace basic

namespace advance {

    struct Subscriber : public std::enable_shared_from_this<Subscriber> {
        using SubscriberPtr = std::shared_ptr<Subscriber>;

        Subscriber(int index)
            : m_index{index} {

        }

        SubscriberPtr getPtr() {
            return shared_from_this();
        }

        void notify() {
            std::cout << "[" << m_index << "] notify" << std::endl;
        }
    private:
        int m_index;
    };

    struct Publisher {
        void subscribe(Subscriber& subscriber) {
            m_subscribers.emplace_back(subscriber.getPtr());
        }

        void makeNotification() {
            for (auto& s : m_subscribers)
                s->notify();
        }
    private:
        std::vector<Subscriber::SubscriberPtr> m_subscribers;
    };

    void example() {
        std::cout << "advance::example" << std::endl;

        Publisher publisher;
        Publisher publisher2;

        const int subsrCount = 5;
        for (int i = 0; i < subsrCount; ++i) {
            Subscriber subscr{i};
            publisher.subscribe(subscr);
            publisher2.subscribe(subscr);
        }

        publisher.makeNotification();
        publisher2.makeNotification();

        std::cout << std::endl;
    }

} // namespace advance

int main() {

    basic::example();
    advance::example();

    return 0;
}