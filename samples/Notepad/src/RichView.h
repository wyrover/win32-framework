//////////////////////////////////////////////
// RichView.h

#ifndef RICHVIEW_H
#define RICHVIEW_H


class CRichView : public CWnd
{
public:
    CRichView(void);
    virtual ~CRichView(void);
    virtual void SetFontDefaults();

protected:
    virtual void PreCreate(CREATESTRUCT &cs);
    virtual void OnInitialUpdate();

private:
    HMODULE m_hInstRichEdit;
    CFont   m_Font;

};

#endif // RICHVIEW_H
