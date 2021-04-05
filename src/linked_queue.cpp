#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
    if (size_ == 0){
        SinglyNode *new_el = new SinglyNode(e, nullptr);
        back_ = new_el;
        front_ = new_el;
        size_++;
    }
    else {
        SinglyNode *new_el = new SinglyNode(e, nullptr);
        back_->next = new_el;
        back_ = new_el;
        size_++;
    }
}

void LinkedQueue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("could not dequeue from empty queue");
  }
    if (size_ == 1){
        delete front_;
        front_ = nullptr;
        back_ = nullptr;
        size_--;
    }
    else if (size_ > 1){

        SinglyNode *new_head = front_->next;
        delete front_;
        front_ = new_head;
        size_--;
    }

  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Clear() {
    SinglyNode *pointer = front_;
    SinglyNode *next_pointer;
    while (pointer != back_){
        next_pointer = pointer->next;
        delete pointer;
        pointer = next_pointer;
    }
    size_ = 0;
    back_ = nullptr;
    front_ = nullptr;
  // TODO: напишите здесь свой код ...
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis