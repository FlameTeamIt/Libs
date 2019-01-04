// Iterators

#define FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX                                 \
Me &operator++() noexcept                                                     \
{                                                                             \
   ++this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX                                \
Me operator++(int) noexcept                                                   \
{                                                                             \
   auto copy = *this;                                                         \
   ++this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX                                 \
Me &operator--() noexcept                                                     \
{                                                                             \
   --this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX                                \
Me operator--(int) noexcept                                                   \
{                                                                             \
   auto copy = *this;                                                         \
   --this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_PREFIX_REVERSED                        \
Me &operator++() noexcept                                                     \
{                                                                             \
   --this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_INC_POSTFIX_REVERSED                       \
Me operator++(int) noexcept                                                   \
{                                                                             \
   auto copy = *this;                                                         \
   --this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_PREFIX_REVERSED                        \
Me &operator--() noexcept                                                     \
{                                                                             \
   ++this->wrappedIterator;                                                   \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEC_POSTFIX_REVERSED                       \
Me operator--(int) noexcept                                                   \
{                                                                             \
   auto copy = *this;                                                         \
   ++this->wrappedIterator;                                                   \
   return copy;                                                               \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEREF                                      \
typename Parent::Reference operator*() noexcept                               \
{                                                                             \
   return *(this->wrappedIterator);                                           \
}

#define FLAMEIDE_ITERATOR_OPERATOR_ARROW                                      \
typename Parent::Pointer operator->() noexcept                                \
{                                                                             \
   return &(*(this->wrappedIterator));                                        \
}

#define FLAMEIDE_ITERATOR_OPERATOR_DEREF_CONST                                \
typename Parent::ConstReference operator*() const noexcept                    \
{                                                                             \
   return *(this->wrappedIterator);                                           \
}

#define FLAMEIDE_ITERATOR_OPERATOR_ARROW_CONST                                \
typename Parent::PointerToConst operator->() const noexcept                   \
{                                                                             \
   return &(*(this->wrappedIterator));                                        \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS                                       \
template<typename IntType> Me operator+(IntType value) const noexcept         \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy += value;                                                             \
   return copy;                                                               \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator) noexcept               \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return iterator + value;                                                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS                                      \
template<typename IntType> Me operator-(IntType value) const noexcept         \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy -= value;                                                             \
   return copy;                                                               \
}                                                                             \
\
typename Parent::SsizeType operator-(const Me &iterator) const noexcept       \
{                                                                             \
   return this->wrappedIterator - iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN                                \
template<typename IntType> Me &operator+=(IntType value) noexcept             \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator += value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN                               \
template<typename IntType> Me &operator-=(IntType value) noexcept             \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator -= value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_REVERSED                              \
template<typename IntType> Me operator+(IntType value) const noexcept         \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy += value;                                                             \
   return copy;                                                               \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator) noexcept               \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return iterator + value; \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_REVERSED                             \
template<typename IntType> Me operator-(IntType value) const noexcept         \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   Me copy = *this;                                                           \
   copy -= value;                                                             \
   return copy;                                                               \
}                                                                             \
\
typename Parent::SsizeType operator-(const Me &iterator) const noexcept       \
{                                                                             \
   return this->wrappedIterator - iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_PLUS_ASSIGN_REVERSED                       \
template<typename IntType> Me &operator+=(IntType value) noexcept             \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator -= value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MINUS_ASSIGN_REVERSED                      \
template<typename IntType> Me &operator-=(IntType value) noexcept             \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   this->wrappedIterator += value;                                            \
   return *this;                                                              \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE                                       \
bool operator>(const Me &iterator) const noexcept                             \
{                                                                             \
   return this->wrappedIterator > iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS                                       \
bool operator<(const Me &iterator) noexcept                                   \
{                                                                             \
   return this->wrappedIterator < iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL                                 \
bool operator>=(const Me &iterator) noexcept                                  \
{                                                                             \
   return this->wrappedIterator >= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL                                 \
bool operator<=(const Me &iterator) noexcept                                  \
{                                                                             \
   return this->wrappedIterator <= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF                               \
template<typename IntType>                                                    \
typename Parent::Reference operator[](IntType value) noexcept                 \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return this->wrappedIterator[value];                                       \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST                         \
template<typename IntType>                                                    \
typename Parent::ConstReference operator[](IntType value) noexcept            \
{                                                                             \
   static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");    \
   return this->wrappedIterator[value];                                       \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_REVERSED                              \
bool operator>(const Me &iterator) noexcept                                   \
{                                                                             \
   return this->wrappedIterator <= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_REVERSED                              \
bool operator<(const Me &iterator) noexcept                                   \
{                                                                             \
   return this->wrappedIterator >= iterator.wrappedIterator;                  \
}

#define FLAMEIDE_ITERATOR_OPERATOR_MORE_EQUAL_REVERSED                        \
bool operator>=(const Me &iterator) noexcept                                  \
{                                                                             \
   return this->wrappedIterator < iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_LESS_EQUAL_REVERSED                        \
bool operator<=(const Me &iterator) noexcept                                  \
{                                                                             \
   return this->wrappedIterator > iterator.wrappedIterator;                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_REVERSED                      \
template<typename IntType>                                                    \
typename Parent::Reference operator[](IntType value) noexcept                 \
{                                                                             \
   return *(this->wrappedIterator - value);                                   \
}

#define FLAMEIDE_ITERATOR_OPERATOR_OFFSET_DEREF_CONST_REVERSED                \
template<typename IntType>                                                    \
typename Parent::ConstReference operator[](IntType value) const noexcept      \
{                                                                             \
   return *(this->wrappedIterator - value);                                   \
}

// IntegerIterator

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_PREFIX                          \
Me &operator++() noexcept                                                     \
{                                                                             \
	++this->wrappedIterator;                                                  \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_INC_POSTFIX                         \
Me operator++(int) noexcept                                                   \
{                                                                             \
	auto copy = *this;                                                        \
	++this->wrappedIterator;                                                  \
	return copy;                                                              \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEC_PREFIX                          \
Me &operator--() noexcept                                                     \
{                                                                             \
	--this->wrappedIterator;                                                  \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEC_POSTFIX                         \
Me operator--(int) noexcept                                                   \
{                                                                             \
	auto copy = *this;                                                        \
	--this->wrappedIterator;                                                  \
	return copy;                                                              \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF                               \
typename Parent::Reference operator*() noexcept                               \
{                                                                             \
	return (this->wrappedIterator);                                           \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW                               \
typename Parent::Pointer operator->() noexcept                                \
{                                                                             \
	return &(this->wrappedIterator);                                          \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_DEREF_CONST                         \
typename Parent::ConstReference operator*() const noexcept                    \
{                                                                             \
	return (this->wrappedIterator);                                           \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_ARROW_CONST                         \
typename Parent::PointerToConst operator->() const noexcept                   \
{                                                                             \
	return &(this->wrappedIterator);                                          \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS                                \
template<typename IntType> Me operator+(IntType value) noexcept               \
{                                                                             \
	Me copy = *this;                                                          \
	copy += value;                                                            \
	return copy;                                                              \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator) noexcept               \
{                                                                             \
	return iterator + value;                                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS                               \
template<typename IntType> Me operator-(IntType value) noexcept               \
{                                                                             \
	Me copy = *this;                                                          \
	copy -= value;                                                            \
	return copy;                                                              \
}                                                                             \
\
typename Parent::SsizeType operator-(const Me &iterator) noexcept             \
{                                                                             \
	return static_cast<Parent::SsizeType>(                                    \
		this->wrappedIterator - iterator.wrappedIterator                      \
	);                                                                        \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_ASSIGN                         \
template<typename IntType> Me &operator+=(IntType value) noexcept             \
{                                                                             \
	this->wrappedIterator += value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_ASSIGN                        \
template<typename IntType> Me &operator-=(IntType value) noexcept             \
{                                                                             \
	this->wrappedIterator -= value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_REVERSED                       \
template<typename IntType> Me operator+(IntType value) noexcept               \
{                                                                             \
	Me copy = *this;                                                          \
	copy += value;                                                            \
	return copy;                                                              \
}                                                                             \
\
template<typename IntType>                                                    \
friend Me operator+(IntType value, const Me &iterator) noexcept               \
{                                                                             \
	return iterator + value;                                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_REVERSED                      \
template<typename IntType> Me operator-(IntType value) noexcept               \
{                                                                             \
	Me copy = *this;                                                          \
	copy -= value;                                                            \
	return copy;                                                              \
}                                                                             \
\
typename Parent::SsizeType operator-(const Me &iterator) noexcept             \
{                                                                             \
	return this->wrappedIterator - iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_PLUS_ASSIGN_REVERSED                \
template<typename IntType> Me &operator+=(IntType value) noexcept             \
{                                                                             \
	this->wrappedIterator -= value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MINUS_ASSIGN_REVERSED               \
template<typename IntType> Me &operator-=(IntType value) noexcept             \
{                                                                             \
	this->wrappedIterator += value;                                           \
	return *this;                                                             \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE                                \
bool operator>(const Me &iterator) noexcept                                   \
{                                                                             \
	return this->wrappedIterator > iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS                                \
bool operator<(const Me &iterator) noexcept                                   \
{                                                                             \
	return this->wrappedIterator < iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_EQUAL                          \
bool operator>=(const Me &iterator) noexcept                                  \
{                                                                             \
	return this->wrappedIterator >= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_EQUAL                          \
bool operator<=(const Me &iterator) noexcept                                  \
{                                                                             \
	return this->wrappedIterator <= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF                        \
template<typename IntType>                                                    \
typename Parent::Reference operator[](IntType value) noexcept                 \
{                                                                             \
	return this->wrappedIterator + value;                                     \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_CONST                  \
template<typename IntType>                                                    \
typename Parent::ConstReference operator[](IntType value) noexcept            \
{                                                                             \
	return this->wrappedIterator + value;                                     \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_REVERSED                       \
bool operator>(const Me &iterator) noexcept                                   \
{                                                                             \
	return this->wrappedIterator <= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_REVERSED                       \
bool operator<(const Me &iterator) noexcept                                   \
{                                                                             \
	return this->wrappedIterator >= iterator.wrappedIterator;                 \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_MORE_EQUAL_REVERSED                 \
bool operator>=(const Me &iterator) noexcept                                  \
{                                                                             \
	return this->wrappedIterator < iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_LESS_EQUAL_REVERSED                 \
bool operator<=(const Me &iterator) noexcept                                  \
{                                                                             \
	return this->wrappedIterator > iterator.wrappedIterator;                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_REVERSED               \
template<typename IntType>                                                    \
typename Parent::Reference operator[](IntType value) noexcept                 \
{                                                                             \
	return *(this->wrappedIterator - value);                                  \
}

#define FLAMEIDE_INTEGERITERATOR_OPERATOR_OFFSET_DEREF_CONST_REVERSED         \
template<typename IntType>                                                    \
typename Parent::ConstReference operator[](IntType value) const noexcept      \
{                                                                             \
	return *(this->wrappedIterator - value);                                  \
}

// CircularIterator

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_INC_PREFIX                         \
Me &operator++() noexcept                                                     \
{                                                                             \
	auto &wrappedIt = internalData();                                         \
	++wrappedIt;                                                              \
	if (wrappedIt == range.end())                                             \
	{                                                                         \
		wrappedIt = range.begin();                                            \
	}                                                                         \
	return *this;                                                             \
}

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_DEC_PREFIX                         \
Me &operator--() noexcept                                                     \
{                                                                             \
	auto &wrappedIt = internalData();                                         \
	--wrappedIt;                                                              \
	if (wrappedIt == range.begin())                                           \
	{                                                                         \
		wrappedIt = --range.end();                                            \
	}                                                                         \
	return *this;                                                             \
}

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_PLUS_ASSIGN                        \
template<typename IntType> Me &operator+=(IntType value) noexcept             \
{                                                                             \
	static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");   \
	auto &wrappedIt = internalData();                                         \
	const auto diff = range.end() - range.begin();                            \
	value = value % diff;                                                     \
	if (wrappedIt + value >= range.end())                                     \
	{                                                                         \
		wrappedIt = range.begin() + (wrappedIt - range.end() + value);        \
	}                                                                         \
	else                                                                      \
	{                                                                         \
		wrappedIt += value;                                                   \
	}                                                                         \
	return *this;                                                             \
}

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_MINUS_ASSIGN                       \
template<typename IntType> Me &operator-=(IntType value) noexcept             \
{                                                                             \
	static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");   \
	auto &wrappedIt = internalData();                                         \
	const auto diff = range.end() - range.begin();                            \
	value = value % diff;                                                     \
	if (wrappedIt - value < range.begin())                                    \
	{                                                                         \
		wrappedIt = range.end() - (range.begin() - wrappedIt + value);        \
	}                                                                         \
	else                                                                      \
	{                                                                         \
		wrappedIt -= value;                                                   \
	}                                                                         \
	return *this;                                                             \
}

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_OFFSET_DEREF                            \
template<typename IntType>                                                         \
typename Parent::Reference operator[](IntType value) noexcept                      \
{                                                                                  \
	static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");        \
	const auto diff = range.end() - range.begin();                                 \
	auto &wrappedIt = internalData();                                              \
	value = value % diff;                                                          \
	if (value > range.end() - wrappedIt)                                           \
	{                                                                              \
		return *(range.begin() + (diff - value));                                  \
	}                                                                              \
	else                                                                           \
	{                                                                              \
		return *(wrappedIt + value);                                               \
	}                                                                              \
}

#define FLAMEIDE_CIRCULARITERATOR_OPERATOR_OFFSET_DEREF_CONST                      \
template<typename IntType>                                                         \
typename Parent::Reference operator[](IntType value) const noexcept                \
{                                                                                  \
	static_assert(IsIntegralType<IntType>::VALUE, "Is not integral type.");        \
	const auto diff = range.end() - range.begin();                                 \
	auto &wrappedIt = internalData();                                              \
	value = value % diff;                                                          \
	if (value > range.end() - wrappedIt)                                           \
	{                                                                              \
		return *(range.begin() + (diff - value));                                  \
	}                                                                              \
	else                                                                           \
	{                                                                              \
		return *(wrappedIt + value);                                               \
	}                                                                              \
}

