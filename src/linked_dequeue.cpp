#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  if (size_ == 0){
      DoublyNode *new_el = new DoublyNode(e, nullptr, nullptr);
      back_ = new_el;
      front_ = new_el;
      size_ ++;

  }
  else {
      DoublyNode *new_el = new DoublyNode(e, back_, nullptr);
      back_->next = new_el;
      back_ = new_el;
      size_ ++;
  }

}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
    if (size_ == 0){
        DoublyNode *new_el = new DoublyNode(e, nullptr, nullptr);
        back_ = new_el;
        front_ = new_el;
        size_ ++;

    }
    else {
        DoublyNode *new_el = new DoublyNode(e, nullptr, front_);
        front_ = new_el;
        size_ ++;
    }
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  DoublyNode *del_head;
  del_head = front_;
  front_ = front_->next;
  delete del_head;
  size_--;


  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  else if ( size_ == 1){
      front_ = nullptr;
      back_ = nullptr;
      size_ --;
  }
  else {

      DoublyNode *del_el = back_;
      back_ = back_->previous;
      delete del_el;
      size_--;
  }
}

void LinkedDequeue::Clear() {
    DoublyNode *pointer = front_;
    DoublyNode *next_pointer ;
    while (pointer != back_){
        next_pointer = pointer->next;
        delete pointer;
        pointer = next_pointer;
    }
    size_ = 0;
    front_ = nullptr;
    back_ = nullptr;
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
