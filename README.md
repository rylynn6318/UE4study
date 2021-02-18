# UE4study

언리얼엔진4 공부
>참고서적 http://www.acornpub.co.kr/book/unreal-c#errata

#### Using 'git status' to determine working set for adaptive non-unity build 에러
BuildConfiguration.xml 파일 수정필요
경로 : Users\AppData\Roaming\Unreal Engine\UnrealBuildTool
```
 <SourceFileWorkingSet> 
          <Provider>None</Provider> 
          <RepositoryPath></RepositoryPath> 
          <GitPath></GitPath> 
 </SourceFileWorkingSet>
```
