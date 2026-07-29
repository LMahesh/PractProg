#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

class EventManager {

private:
    std::map<std::string, std::vector<void (*)(int)>> events;

public:
    EventManager() {}

    EventManager* on(std::string event_name, void (*callback)(int)) {

        // we're using a pointer to reference `events[event_name]` so as
        // to get reference to original object and not the copy object.
        std::vector<void (*)(int)>* listeners = &events[event_name];

        // if this listener is already registered, we wont add it again
        if (std::find(listeners->begin(), listeners->end(), callback) != listeners->end()) {
            return this;
        }

        listeners->push_back(callback);

        return this;
    }

    bool emit(std::string event_name, int arg) {
        std::vector<void (*)(int)> listeners = events[event_name];

        if (listeners.size() == 0) return false;

        // Run all the listeners associated with the event
        for (int idx = 0; idx < listeners.size(); idx += 1) {
            listeners[idx](arg);
        }

        return true;
    }
};

void callback1(int num) {
    std::cout << "\n";
    std::cout << "callback1-" << num * 2;
}

void callback2(int num) {
    std::cout << "\n";
    std::cout << "callback2-" << num / 2;
}

int main() {
    EventManager* event_manager = new EventManager();
    event_manager->on("event", callback1)->on("event", callback2);

    int eventA = event_manager->emit("event", 100);
    int eventB = event_manager->emit("bad_event", 200);
    

    std::cout << "\n";
    std::cout << eventA << " " << eventB << "\n";


    return 0;
}