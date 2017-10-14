
#include "blend_dialog.h"
#include "ui_blend_dialog.h"

blend_dialog::blend_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blend_dialog)
{
    ui->setupUi(this);
    /*
    zero=GL_ZERO,
    one=GL_ONE,
    src_color=GL_SRC_COLOR,
    one_minus_src_color=GL_ONE_MINUS_SRC_COLOR,
    dst_color=GL_DST_COLOR,
    one_minus_dst_color=GL_ONE_MINUS_DST_COLOR,
    src_alpha=GL_SRC_ALPHA,
    one_minus_src_alpha=GL_ONE_MINUS_SRC_ALPHA,
    dst_alpha=GL_DST_ALPHA,
    one_minus_dst_alpha=GL_ONE_MINUS_DST_ALPHA,
    constant_color=GL_CONSTANT_COLOR,
    one_minus_constant_color=GL_ONE_MINUS_CONSTANT_COLOR,
    constant_alpha=GL_CONSTANT_ALPHA,
    one_minus_constant_alpha=GL_ONE_MINUS_CONSTANT_ALPHA,
    src_alpha_saturate=GL_SRC_ALPHA_SATURATE,
    src1_color=GL_SRC1_COLOR,
    one_minus_src1_color=GL_ONE_MINUS_SRC1_COLOR,
    src1_alpha=GL_SRC1_ALPHA,
    one_minus_src1_alpha=GL_ONE_MINUS_SRC1_ALPHA,
    */
    ui->cb_source->addItem("zero",QVariant(GL_ZERO));
    ui->cb_source->addItem("one",QVariant(GL_ONE));
    ui->cb_source->addItem("src_color",QVariant(GL_SRC_COLOR));
    ui->cb_source->addItem("one_minus_src_color",QVariant(GL_ONE_MINUS_SRC_COLOR));
    ui->cb_source->addItem("dst_color",QVariant(GL_DST_COLOR));
    ui->cb_source->addItem("one_minus_dst_color",QVariant(GL_ONE_MINUS_DST_COLOR));
    ui->cb_source->addItem("src_alpha",QVariant(GL_SRC_ALPHA));
    ui->cb_source->addItem("one_minus_src_alpha",QVariant(GL_ONE_MINUS_SRC_ALPHA));
    ui->cb_source->addItem("dst_alpha",QVariant(GL_DST_ALPHA));
    ui->cb_source->addItem("one_minus_dst_alpha",QVariant(GL_ONE_MINUS_DST_ALPHA));
    ui->cb_source->addItem("constant_color",QVariant(GL_CONSTANT_COLOR));
    ui->cb_source->addItem("one_minus_costant_color",QVariant(GL_ONE_MINUS_CONSTANT_COLOR));
    ui->cb_source->addItem("constant_alpha",QVariant(GL_CONSTANT_ALPHA));
    ui->cb_source->addItem("one_minus_costant_alpha",QVariant(GL_ONE_MINUS_CONSTANT_ALPHA));
    ui->cb_source->addItem("src_alpha_saturate",QVariant(GL_SRC_ALPHA_SATURATE));
    ui->cb_source->addItem("src1_color",QVariant(GL_SRC1_COLOR));
    ui->cb_source->addItem("one_minus_src1_color",QVariant(GL_ONE_MINUS_SRC1_COLOR));
    ui->cb_source->addItem("src1_alpha",QVariant(GL_SRC1_ALPHA));
    ui->cb_source->addItem("one_minus_src1_alpha",QVariant(GL_ONE_MINUS_SRC1_ALPHA));

    ui->cb_dest->addItem("zero",QVariant(GL_ZERO));
    ui->cb_dest->addItem("one",QVariant(GL_ONE));
    ui->cb_dest->addItem("src_color",QVariant(GL_SRC_COLOR));
    ui->cb_dest->addItem("one_minus_src_color",QVariant(GL_ONE_MINUS_SRC_COLOR));
    ui->cb_dest->addItem("dst_color",QVariant(GL_DST_COLOR));
    ui->cb_dest->addItem("one_minus_dst_color",QVariant(GL_ONE_MINUS_DST_COLOR));
    ui->cb_dest->addItem("src_alpha",QVariant(GL_SRC_ALPHA));
    ui->cb_dest->addItem("one_minus_src_alpha",QVariant(GL_ONE_MINUS_SRC_ALPHA));
    ui->cb_dest->addItem("dst_alpha",QVariant(GL_DST_ALPHA));
    ui->cb_dest->addItem("one_minus_dst_alpha",QVariant(GL_ONE_MINUS_DST_ALPHA));
    ui->cb_dest->addItem("constant_color",QVariant(GL_CONSTANT_COLOR));
    ui->cb_dest->addItem("one_minus_costant_color",QVariant(GL_ONE_MINUS_CONSTANT_COLOR));
    ui->cb_dest->addItem("constant_alpha",QVariant(GL_CONSTANT_ALPHA));
    ui->cb_dest->addItem("one_minus_costant_alpha",QVariant(GL_ONE_MINUS_CONSTANT_ALPHA));
    ui->cb_dest->addItem("src_alpha_saturate",QVariant(GL_SRC_ALPHA_SATURATE));
    ui->cb_dest->addItem("src1_color",QVariant(GL_SRC1_COLOR));
    ui->cb_dest->addItem("one_minus_src1_color",QVariant(GL_ONE_MINUS_SRC1_COLOR));
    ui->cb_dest->addItem("src1_alpha",QVariant(GL_SRC1_ALPHA));
    ui->cb_dest->addItem("one_minus_src1_alpha",QVariant(GL_ONE_MINUS_SRC1_ALPHA));

}

blend_dialog::~blend_dialog()
{
    delete ui;
}

void blend_dialog::on_buttonBox_accepted()
{
    int is=ui->cb_source->currentIndex();
    int id=ui->cb_dest->currentIndex();
    QVariant sv=ui->cb_source->itemData(is),
            dv=ui->cb_dest->itemData(id);
    _sfactor=(l3d::mesh::blendFunction)sv.toInt();
    _dfactor=(l3d::mesh::blendFunction)dv.toInt();
}
