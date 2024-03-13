#ifndef FLAMEIDE_TEMPLATES_TREE_BINARYTREEIMPL_HPP
#define FLAMEIDE_TEMPLATES_TREE_BINARYTREEIMPL_HPP

namespace flame_ide
{namespace templates
{namespace tree
{namespace impl
{

template<typename TreeNode, typename TreeComparator>
class BinaryTreeImpl
{
public:
	using Me = BinaryTreeImpl<TreeNode, TreeComparator>;

	BinaryTreeImpl() noexcept = default;
	BinaryTreeImpl(const Me &) noexcept = default;
	BinaryTreeImpl(Me &&) noexcept = default;
	~BinaryTreeImpl() noexcept = default;

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	template<typename Context, typename NodeCreator, typename ...Args>
	void pushImpl(Context &context, NodeCreator &&creator, Args &&...args) noexcept;

	template<typename Context, typename NodeDestroyer>
	void eraseImpl(TreeNode *node, Context &context, NodeDestroyer &&destroyer) noexcept;
};

}}}} // namespace flame_ide::templates::tree::impl

namespace flame_ide
{namespace templates
{namespace tree
{namespace impl
{

template<typename TreeNode, typename TreeComparator>
template<typename Context, typename NodeCreator, typename ...Args>
void BinaryTreeImpl<TreeNode, TreeComparator>::pushImpl(
		Context &context, NodeCreator &&creator, Args &&...args
) noexcept
{}

template<typename TreeNode, typename TreeComparator>
template<typename Context, typename NodeDestroyer>
void BinaryTreeImpl<TreeNode, TreeComparator>::eraseImpl(
		TreeNode *node, Context &context, NodeDestroyer &&destroyer
) noexcept
{}

}}}} // namespace flame_ide::templates::tree::impl

#endif // FLAMEIDE_TEMPLATES_TREE_BINARYTREEIMPL_HPP
