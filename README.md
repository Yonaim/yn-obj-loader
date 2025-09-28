# yn_obj_loader

The .obj file loader library on my own. The prefix 'yn' is just the acronym of my nickname (not special meaning)
Like the famous obj loader library `tinyobj`, this library aims to simple, too.

# Structure

- obj 파일의 내용을 파싱하고 그 내용 그대로 돌려주는 선에서 그치고, 후처리는 사용자의 몫으로 남겨둔다
    - 따라서 loader 구조체는 제공하지 않는다.
    - 옵션은 triangulator만 제공
- loader > reader > parser
    - loader 구조체는 존재하지 않음
    - 내부 구조체는 reader 단계부터 존재

- global declaration
    - loader에서 전역적으로 사용하는 데이터
    - 정점 데이터, 재질 라이브러리, 스무딩 그룹
    - primitive 타입 (polygon mesh, polyline, point cloud)


## Reader

- 클래스로 제공
- config 구조체 존재
- 데이터 멤버
    - attributes
    - shapes
    - materials

## Parser

- obj 파일의 구조가 매우 간단하므로, AST(Abstract Structured Tree)는 필요없다
- 파서의 역할도 굉장히 간단: 그저 읽고 바로 구조체에 넣는다. state 없다.
- 따라서 클래스로 제공할 필요는 없음. 
- 아마 namespace로 scope 분리만 할듯

# Memo

## .obj file
- 정점 정보(v, vt, vn)은 전역적임 (global)
- 여러 오브젝트 태그(o)가 등장하더라도 마찬가지
- 전역적인 정점 정보를 여러 오브젝트가 참조할 수 있음

## o, g 키워드 처리 (object, group)

- o와 g는 optional keywords (필수가 아님)
    - 파일내의 키워드 등장 유무에 따라 달리 처리
- tinyobj
    - object와 group을 위한 구조체는 따로 없음
    - 대신 중립적인 구조체 `shape_t`만 둠.
    - `shape_t`는 object일수도, group일수도 있음.
    - 간단하게, '묶는 단위'로 해석


# References

- https://github.com/tinyobjloader/tinyobjloader/blob/release/tiny_obj_loader.h
- https://paulbourke.net/dataformats/obj/
- https://en.wikipedia.org/wiki/Wavefront_.obj_file
- https://www.loc.gov/preservation/digital/formats/fdd/fdd000507.shtml