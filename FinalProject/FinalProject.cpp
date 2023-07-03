#include <iostream>
using namespace std;

class Matakuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;
public:
	Matakuliah() {
		presensi = 0;
		activity = 0;
		exercise = 0;
		tugasAkhir = 0;
	}

	virtual float hitungNilaiAkhir() { return 0; }
	virtual void cekKelulusan() { return; }
	virtual void input() { return; }

	void setP(float nilai) {
		this->presensi = nilai;
	}

	float getP() {
		return presensi;
	}

	void setA(float nilai) {
		this->activity = nilai;
	}

	float getA() {
		return activity;
	}

	void setE(float nilai) {
		this->exercise = nilai;
	}

	float getE() {
		return exercise;
	}

	void setUA(float nilai) {
		this->tugasAkhir = nilai;
	}

	float getUA() {
		return tugasAkhir;
	}
};

class Pemrograman : public Matakuliah {
public:
	void input() {
		float presensi;
		cout << "Masukkan nilai Presensi : ";
		cin >> presensi;
		setP(presensi);

		float activity;
		cout << "Masukkan nilai Activity : ";
		cin >> activity;
		setA(activity);

		float exercise;
		cout << "Masukkan nilai Exercise : ";
		cin >> exercise;
		setE(exercise);

		float tugasAkhir;
		cout << "Masukkan nilai Tugas Akhir : ";
		cin >> tugasAkhir;
		setUA(tugasAkhir);
	}

	float hitungNilaiAkhir() {
		float nilaiAkhir = getP() * 0.1 + getA() * 0.2 + getE() * 0.3 + getUA() * 0.4;
		return nilaiAkhir;
	}

	void cekKelulusan() {
		float nilaiAkhir = hitungNilaiAkhir();

		if (nilaiAkhir > 75) {
			cout << "Selamat, Anda dinyatakan lulus mata kuliah Pemrograman dengan nilai akhir : " << nilaiAkhir << endl;
		}
		else {
			cout << "Maaf, Anda dinyatakan tidak lulus mata kuliah Pemrograman dengan nilai akhir : " << nilaiAkhir << endl;
		}		
	}
};

int main() {
	char kembali;
	do {
		cout << "Program dibuat" << endl;
		Pemrograman pemrograman;
		pemrograman.input();
		pemrograman.cekKelulusan();

		cout << "Apakah Anda ingin mengulang program? (Y/N) : ";
		cin >> kembali;
	} while (kembali == 'Y' || kembali == 'y');

	return 0;
}
	