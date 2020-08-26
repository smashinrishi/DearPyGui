#pragma once

#include "mvAppItem.h"
#include "mvTypeBases.h"
#include "mvApp.h"
#include "mvAppLog.h"

//-----------------------------------------------------------------------------
// Widget Index
//
//     * mvEditor
//
//-----------------------------------------------------------------------------

namespace Marvel {

	class mvTextEditor;

	class mvEditor : public mvAppItem
	{

	public:

		MV_APPITEM_TYPE(mvAppItemType::Editor)

		mvEditor(const std::string& parent, const std::string& name);
		~mvEditor();

		mvTextEditor* getEditor() { return m_editor; }

		void setPyValue(PyObject* value) override;
		[[nodiscard]] PyObject* getPyValue() const override;
		void draw() override;

	private:

		std::string m_value;
		mvTextEditor* m_editor;
	};

}