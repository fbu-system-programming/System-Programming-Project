#pragma once
#include <string>
#include "student.hpp"

bool is_positive_id(int id);
bool is_valid_email(const std::string& email);
bool validate_student(const Student& s, std::string& error);
