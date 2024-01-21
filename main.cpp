#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QFont>

class SkeletonizedImage : public QLabel {
public:
    SkeletonizedImage(QWidget *parent = nullptr) : QLabel(parent) {
        QPixmap outlineImage("C:/Users/brum-/OneDrive/Documentos/TFLegibleCompactImages/morcego.jpg");
        QImage img = outlineImage.toImage();

        applySkeletonization(img);

        drawTextOnSkeleton(img, "morcego");

        setPixmap(QPixmap::fromImage(img));
    }

private:
    void applySkeletonization(QImage &image) {
        image.invertPixels();
    }

    void drawTextOnSkeleton(QImage &image, const QString &text) {
        // Configurar uma fonte para o texto
        QFont font;
        font = QFont("Futura");
        font.setPointSize(20); // Tamanho da fonte
        font.setBold(true);

        // Configurar um pintor para desenhar na imagem
        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setFont(font);

        // Encontrar a linha principal (substitua isso pela lógica real)
        QPoint lineStart(50, 100);  // Exemplo: ponto de partida arbitrário

        // Desenhar o texto na linha principal
        painter.drawText(lineStart, text);
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Criar e exibir a janela com a imagem esqueletonizada e o texto
    SkeletonizedImage window;
    window.show();

    return a.exec();
}
