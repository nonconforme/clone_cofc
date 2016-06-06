//
//  DtoTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2016/04/21.
//
//

#import <XCTest/XCTest.h>
#include "AssetXmlAssembler.h"
#include "TAssetTable.h"

@interface DtoTestCase : XCTestCase

@end

@implementation DtoTestCase

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    FileUtils* file = FileUtils::getInstance();
    file->addSearchPath("docs");
    std::string ret = file->getStringFromFile("docs/xml/sample.xml");
    AssetXmlAssembler assembler(ret);
    std::vector<TAssetTable> recordList = assembler.writeToRecordList();
    XCTAssertEqual(recordList.size(), 2);
    
    // This is an example of ret =  a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
