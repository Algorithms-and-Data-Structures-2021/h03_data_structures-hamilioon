#include "linked_stack.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedStack::Push(Element e) {
    if (size_ == 0){
        SinglyNode *top = new SinglyNode(e, nullptr);
        size_++;
        top_ = top;
    }
    else if(size_ > 0 ) {
        SinglyNode *top = new SinglyNode(e, top_);
        top_ = top;
        size_++;
    }


  // TODO: напишите здесь свой код ...
}

void LinkedStack::Pop() {
  if (top_ == nullptr) {
    throw std::logic_error("cannot pop out from empty stack");
  }

  if (size_ == 1){
      delete top_;
      top_ = nullptr;
      size_ = 0;

  }
  else{
      SinglyNode *pointer_to_new_top = top_->next;
      delete top_;
      top_ = pointer_to_new_top;
      size_--;

  }
  // TODO: напишите здесь свой код ...
}


void LinkedStack::Clear() {
  // TODO: напишите здесь свой код ...
    if (size_ != 0) {
        SinglyNode *pointer = top_;
        SinglyNode *next_pointer;
        if (size_ != 1) {
            while (pointer->next != nullptr) {
                next_pointer = pointer->next;
                delete pointer;
                pointer = next_pointer;
            }
            size_ = 0;
            top_ = nullptr;
        }
        else{
            delete top_;
            top_ = nullptr;
            size_ = 0;
        }
    }
    else{
        top_ = nullptr;
        size_ = 0;
    }
}

// === РЕАЛИЗОВАНО ===

LinkedStack::~LinkedStack() {
  Clear();
}

std::optional<Element> LinkedStack::Peek() const {
  return top_ == nullptr ? std::nullopt : std::make_optional(top_->data);
}

bool LinkedStack::IsEmpty() const {
  return size_ == 0;
}

int LinkedStack::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedStack &stack) {
  os << "size: " << stack.size_ << '\n';
  for (auto current_node = stack.top_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == stack.top_) os << "[TOP] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis