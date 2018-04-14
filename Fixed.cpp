//
// Created by Bogdan Semchuk on 1/18/18.
//
#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	this->_fixedPoint = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(int const i) {
	this->_fixedPoint = (i * (1 << this->_rawBits));
}

Fixed::Fixed(float const f) {
	this->_fixedPoint = (roundf(f * (1 << this->_rawBits)));
}

std::ostream &operator<<( std::ostream &output, const Fixed &number ) {
	output << (number.toFloat());
	return output;
}

Fixed &Fixed::operator=(Fixed const &fixed) {
	if (this != &fixed)
		this->_fixedPoint = (fixed.getRawBits());
	return *this;
}

Fixed::Fixed(Fixed const &fixed) {
	this->setRawBits(fixed.getRawBits());
}

int Fixed::getRawBits() const {
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

int Fixed::toInt() const {
	return (this->_fixedPoint >> this->_rawBits);
}

float Fixed::toFloat() const {
	float f;
	f = (float)(this->_fixedPoint) / (1 << this->_rawBits);
	return f;
}

bool	Fixed::operator>(Fixed const &fixed) const {
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed const &fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed const &fixed) const {
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed const &fixed) const {
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed const &fixed) const {
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed const &fixed) const {
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+(Fixed const &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator++() {
	++(this->_fixedPoint);
	return Fixed(this->toFloat());
}

Fixed	Fixed::operator++(int) {
	this->_fixedPoint++;
	return Fixed(this->toFloat());
}

Fixed Fixed::operator--() {
	--this->_fixedPoint;
	return Fixed(this->toFloat());
}

Fixed Fixed::operator--(int) {
	this->_fixedPoint--;
	return Fixed(this->toFloat());
}

Fixed& Fixed::max(Fixed &fixed, Fixed &fixed2)
{
	return ((fixed > fixed2) ? fixed : fixed2);
}

Fixed& Fixed::min(Fixed &fixed, Fixed &fixed2)
{
	return ((fixed < fixed2) ? fixed : fixed2);
}

const Fixed &Fixed::min(Fixed const &fixed, Fixed const &fixed2)
{
	return ((fixed < fixed2) ? fixed : fixed2);
}

const Fixed &Fixed::max(Fixed const &fixed, Fixed const &fixed2)
{
	return ((fixed > fixed2) ? fixed : fixed2);
}
