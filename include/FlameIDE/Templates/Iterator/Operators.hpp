// Iterators

#define FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX                                 \
Me &operator++()                                                              \
{                                                                             \
   ++this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX                                \
Me operator++(int)                                                            \
{                                                                             \
   auto copy = *this;                                                         \
   ++this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX                                 \
Me &operator--()                                                              \
{                                                                             \
   --this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX                                \
Me operator--(int)                                                            \
{                                                                             \
   auto copy = *this;                                                         \
   --this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX_REVERSED                        \
Me &operator++()                                                              \
{                                                                             \
   --this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX_REVERSED                       \
Me operator++(int)                                                            \
{                                                                             \
   auto copy = *this;                                                         \
   --this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX_REVERSED                        \
Me &operator--()                                                              \
{                                                                             \
   ++this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX_REVERSED                       \
Me operator--(int)                                                            \
{                                                                             \
   auto copy = *this;                                                         \
   ++this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEREF                                      \
typename Traits::Reference operator*()                                        \
{                                                                             \
   return *(this->wrappedIterator);                                           \
}

#define FLAMEIDE_ITERATOR_OPERATOR_ARROW                                      \
typename Traits::Pointer operator->()                                         \
{                                                                             \
   return &(*(this->wrappedIterator));                                        \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST                                \
typename Traits::ConstReference operator*() const                             \
{                                                                             \
   return *(this->wrappedIterator);                                           \
}

#define FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST                                \
typename Traits::PointerToConst operator->() const                            \
{                                                                             \
   return &(*(this->wrappedIterator));                                        \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS                                       \
template<typename IntType> Me operator+(IntType value) const                  \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy += value;                                                             \
   return copy;                                                               \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator)                        \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return iterator + value;                                                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS                                      \
template<typename IntType> Me operator-(IntType value) const                  \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy -= value;                                                             \
   return copy;                                                               \
}                                                                             \
\
typename Traits::SsizeType operator-(const Me &iterator) const                \
{                                                                             \
   return this->wrappedIterator - iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN                                \
template<typename IntType> Me &operator+=(IntType value)                      \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator += value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN                               \
template<typename IntType> Me &operator-=(IntType value)                      \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator -= value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_REVERSED                              \
template<typename IntType> Me operator+(IntType value) const                  \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy += value;                                                             \
   return copy;                                                               \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator)                        \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return iterator + value; \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_REVERSED                             \
template<typename IntType> Me operator-(IntType value) const                  \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy -= value;                                                             \
   return copy;                                                               \
}                                                                             \
\
typename Traits::SsizeType operator-(const Me &iterator) const                \
{                                                                             \
   return this->wrappedIterator - iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN_REVERSED                       \
template<typename IntType> Me &operator+=(IntType value)                      \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator -= value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN_REVERSED                      \
template<typename IntType> Me &operator-=(IntType value)                      \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator += value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE                                       \
bool operator>(const Me &iterator) const                                      \
{                                                                             \
   return this->wrappedIterator > iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS                                       \
bool operator<(const Me &iterator)                                            \
{                                                                             \
   return this->wrappedIterator < iterator;                                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL                                 \
bool operator>=(const Me &iterator)                                           \
{                                                                             \
   return this->wrappedIterator >= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL                                 \
bool operator<=(const Me &iterator)                                           \
{                                                                             \
   return this->wrappedIterator <= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF                               \
template<typename IntType>                                                    \
typename Traits::Reference operator[](IntType value)                          \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return this->wrappedIterator[value];                                       \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST                         \
template<typename IntType>                                                    \
typename Traits::ConstReference operator[](IntType value)                     \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return this->wrappedIterator[value];                                       \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_REVERSED                              \
bool operator>(const Me &iterator)                                            \
{                                                                             \
   return this->wrappedIterator <= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_REVERSED                              \
bool operator<(const Me &iterator)                                            \
{                                                                             \
   return this->wrappedIterator >= iterator;                                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL_REVERSED                        \
bool operator>=(const Me &iterator)                                           \
{                                                                             \
   return this->wrappedIterator < iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL_REVERSED                        \
bool operator<=(const Me &iterator)                                           \
{                                                                             \
   return this->wrappedIterator > iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_REVERSED                      \
template<typename IntType>                                                    \
typename Traits::Reference operator[](IntType value)                          \
{                                                                             \
   return *(this->wrappedIterator - value);                                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST_REVERSED                \
template<typename IntType>                                                    \
typename Traits::ConstReference operator[](IntType value) const               \
{                                                                             \
   return *(this->wrappedIterator - value);                                   \
}

// IntegerIterator

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_PREFIX                          \
Me &operator++()                                                              \
{                                                                             \
	++this->wrappedIterator;                                                  \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_POSTFIX                         \
Me operator++(int)                                                            \
{                                                                             \
	auto copy = *this;                                                        \
	++this->wrappedIterator;                                                  \
	return copy;                                                              \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEC_PREFIX                          \
Me &operator--()                                                              \
{                                                                             \
	--this->wrappedIterator;                                                  \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEC_POSTFIX                         \
Me operator--(int)                                                            \
{                                                                             \
	auto copy = *this;                                                        \
	--this->wrappedIterator;                                                  \
	return copy;                                                              \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF                               \
typename Traits::Reference operator*()                                        \
{                                                                             \
	return (this->wrappedIterator);                                           \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW                               \
typename Traits::Pointer operator->()                                         \
{                                                                             \
	return &(this->wrappedIterator);                                          \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF_CONST                         \
typename Traits::ConstReference operator*() const                             \
{                                                                             \
	return (this->wrappedIterator);                                           \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW_CONST                         \
typename Traits::PointerToConst operator->() const                            \
{                                                                             \
	return &(this->wrappedIterator);                                          \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS                                \
template<typename IntType> Me operator+(IntType value)                        \
{                                                                             \
	Me copy = *this;                                                          \
	copy += value;                                                            \
	return copy;                                                              \
}                                                                             \
                                                                              \
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator)                        \
{                                                                             \
	return iterator + value;                                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS                               \
template<typename IntType> Me operator-(IntType value)                        \
{                                                                             \
	Me copy = *this;                                                          \
	copy -= value;                                                            \
	return copy;                                                              \
}                                                                             \
                                                                              \
typename Traits::SsizeType operator-(const Me &iterator)                      \
{                                                                             \
	return static_cast<Traits::SsizeType>(                                    \
		this->wrappedIterator - iterator.wrappedIterator                      \
	);                                                                        \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_ASSIGN                         \
template<typename IntType> Me &operator+=(IntType value)                      \
{                                                                             \
	this->wrappedIterator += value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_ASSIGN                        \
template<typename IntType> Me &operator-=(IntType value)                      \
{                                                                             \
	this->wrappedIterator -= value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_REVERSED                       \
template<typename IntType> Me operator+(IntType value)                        \
{                                                                             \
	Me copy = *this;                                                          \
	copy += value;                                                            \
	return copy;                                                              \
}                                                                             \
                                                                              \
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator)                        \
{                                                                             \
	return iterator + value;                                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_REVERSED                      \
template<typename IntType> Me operator-(IntType value)                        \
{                                                                             \
	Me copy = *this;                                                          \
	copy -= value;                                                            \
	return copy;                                                              \
}                                                                             \
                                                                              \
typename Traits::SsizeType operator-(const Me &iterator)                      \
{                                                                             \
	return this->wrappedIterator - iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_ASSIGN_REVERSED                \
template<typename IntType> Me &operator+=(IntType value)                      \
{                                                                             \
	this->wrappedIterator -= value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_ASSIGN_REVERSED               \
template<typename IntType> Me &operator-=(IntType value)                      \
{                                                                             \
	this->wrappedIterator += value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE                                \
bool operator>(const Me &iterator)                                            \
{                                                                             \
	return this->wrappedIterator > iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS                                \
bool operator<(const Me &iterator)                                            \
{                                                                             \
	return this->wrappedIterator < iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_EQUAL                          \
bool operator>=(const Me &iterator)                                           \
{                                                                             \
	return this->wrappedIterator >= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_EQUAL                          \
bool operator<=(const Me &iterator)                                           \
{                                                                             \
	return this->wrappedIterator <= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF                        \
template<typename IntType>                                                    \
typename Traits::Reference operator[](IntType value)                          \
{                                                                             \
	return this->wrappedIterator + value;                                     \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_CONST                  \
template<typename IntType>                                                    \
typename Traits::ConstReference operator[](IntType value)                     \
{                                                                             \
	return this->wrappedIterator + value;                                     \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_REVERSED                       \
bool operator>(const Me &iterator)                                            \
{                                                                             \
	return this->wrappedIterator <= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_REVERSED                       \
bool operator<(const Me &iterator)                                            \
{                                                                             \
	return this->wrappedIterator >= iterator;                                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_EQUAL_REVERSED                 \
bool operator>=(const Me &iterator)                                           \
{                                                                             \
	return this->wrappedIterator < iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_EQUAL_REVERSED                 \
bool operator<=(const Me &iterator)                                           \
{                                                                             \
	return this->wrappedIterator > iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_REVERSED               \
template<typename IntType>                                                    \
typename Traits::Reference operator[](IntType value)                          \
{                                                                             \
	return *(this->wrappedIterator - value);                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_CONST_REVERSED         \
template<typename IntType>                                                    \
typename Traits::ConstReference operator[](IntType value) const               \
{                                                                             \
	return *(this->wrappedIterator - value);                                  \
}
