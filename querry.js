var i, j, k, count = 0;
var diemthi, ht;
for(i = 0; i < 10; i++) {
	ht = "sinhvien_" + i;
	db.SINHVIEN.insert({
	masv: i,
	hoten: ht});
}
var mh;
for(i = 0; i < 10; i++){
	mh = "monhoc_" + i;
	db.MONHOC.insert({
	mamon: i,
	tenmon: mh});
}
var t = 0;
for(i = 0; i < 10; i++)
for(j = 0; j < 10; j++)
{
	for(k = 0; k < 100000; k++) 
	{
	diemthi =  Math.floor(Math.random() * 11); // random diem from 0-10
	db.BANGDIEM.insertMany([
	{
	masv: i,
	mamon: j,
	diem: diemthi,
	thoigian: t},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+1},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+2},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+3},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+4},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+5},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+6},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+7},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+8},
	{
	masv: i,
        mamon: j,
        diem: diemthi,
        thoigian: t+9
	}]);
	t = t + 10;
	}
}
	
