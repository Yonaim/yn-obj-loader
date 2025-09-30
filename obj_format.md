## Geometry

* `v x y z [w]`
  Vertex 좌표 (w는 생략 가능, 기본 1.0)

* `vt u [v [w]]`
  Texture 좌표 (2D 또는 3D)

* `vn x y z`
  Normal 벡터

* `vp u [v [w]]`
  Parameter space vertex (곡선/곡면용)

---

## Topology / Elements

* `f v1[/vt1[/vn1]] v2[/vt2[/vn2]] ...`
  Face (다각형, 일반적으로 삼각형 또는 사각형)

* `l v1[/vt1] v2[/vt2] ...`
  Line element (폴리라인)

* `p v1 v2 ...`
  Point element

---

## group & object

* `o object_name`
  Object 이름 정의

* `g group_name1 group_name2 ...`
  Group 이름 정의 (하나의 요소가 여러 그룹에 속할 수 있음)

* `s off`
  Smoothing group 끄기

* `s number`
  Smoothing group 번호 지정

---

## Materials

* `mtllib filename.mtl`
  재질 라이브러리 파일 참조

* `usemtl material_name`
  이후 요소에 적용할 재질 지정
