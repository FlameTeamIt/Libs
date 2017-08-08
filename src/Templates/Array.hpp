#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/IntializerList.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief Array
 */
template<class T, SizeTraits::SizeType SIZE, typename Traits = ContainerTraits<T>>
class Array
{
public:
	using SizeType = typename Traits::SizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Iterator = Pointer;
	using ConstIterator = PointerToConst;

	/**
	 * @brief Array
	 */
	Array() = default;

	/**
	 * @brief Array
	 * @param array
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits2>
	Array(const Array<T, SIZE1, Traits2> &array);

	/**
	 * @brief Array
	 * @param array
	 */
	Array(const Array<T, SIZE, Traits> &array);

	/**
	 * @brief Array
	 * @param array
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits2>
	Array(Array<T, SIZE1, Traits2> &&array);

	/**
	 * @brief Array
	 * @param array
	 */
	Array(Array &&array);

	/**
	 * @brief Array
	 * @param list
	 */
	Array(InitializerList<T, SIZE> list);

	~Array();

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	Array<T, SIZE, Traits> &operator=(const Array<T, SIZE, Traits> &array);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits2>
	Array<T, SIZE, Traits> &operator=(const Array<T, SIZE1, Traits2> &array);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	Array<T, SIZE, Traits> &operator=(Array<T, SIZE, Traits> &&array);

	/**
	 * @brief operator =
	 * @param array
	 * @return
	 */
	template<SizeTraits::SizeType SIZE1, typename Traits2>
	Array<T, SIZE, Traits> &operator=(Array<T, SIZE1, Traits2> &&array);

	/**
	 * @brief size
	 * @return
	 */
	inline typename Traits::SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @return
	 */
	inline constexpr typename Traits::SizeType capacity() const noexcept;

	/**
	 * @brief begin
	 * @return
	 */
	Iterator begin() noexcept;

	/**
	 * @brief begin
	 * @return
	 */
	ConstIterator begin() const noexcept;

	/**
	 * @brief end
	 * @return
	 */
	Iterator end() noexcept;

	/**
	 * @brief end
	 * @return
	 */
	ConstIterator end() const noexcept;

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(ConstReference object);

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(MoveReference object);

	/**
	 * @brief popBack
	 * @return
	 */
	Type popBack();

	/**
	 *
	 */
	template<typename InputIterator, bool copy = TrueType::VALUE>
	void insert(Iterator it, InputIterator begin, InputIterator end);

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, ConstReference type);

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, MoveReference type);

private:
	Types::byte_t bytes[sizeof(Type) * SIZE];

	/**
	 * @brief The Objects union
	 */
	union Objects
	{
		Objects() = default;

		/**
		 * @brief Objects
		 * @param initArray
		 */
		Objects(Pointer initArray) : array(initArray)
		{}

		Objects(DefaultTraits<Types::byte_t>::Pointer initArray) : bytes(initArray)
		{}

		DefaultTraits<Types::byte_t>::Pointer bytes;
		Pointer array;
	} objects;
	Pointer tail;
};

}}

namespace flame_ide
{namespace templates
{

template<class T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::Array(InitializerList<T, SIZE> list) : objects(bytes)
{
	Pointer pointer = this->objects.array;
	for (auto it : list)
	{
		placementNew<Type>(pointer, it);
	}
	tail = pointer;
}

template<class T, SizeTraits::SizeType SIZE, typename Traits>
Array<T, SIZE, Traits>::~Array()
{}


}}

#endif // TEMPLATES_ARRAY
